#include <appbase/application.hpp>
#include <sophiatx/manifest/plugins.hpp>

#include <sophiatx/protocol/types.hpp>
#include <sophiatx/protocol/version.hpp>

#include <sophiatx/utilities/key_conversion.hpp>
#include <sophiatx/utilities/git_revision.hpp>

#include <sophiatx/plugins/chain/chain_plugin_full.hpp>
#include <sophiatx/plugins/p2p/p2p_plugin.hpp>
#include <sophiatx/plugins/webserver/webserver_plugin.hpp>

#include <fc/exception/exception.hpp>
#include <fc/thread/thread.hpp>
#include <fc/interprocess/signals.hpp>
#include <fc/git_revision.hpp>
#include <fc/stacktrace.hpp>

#include <boost/exception/diagnostic_information.hpp>
#include <boost/program_options.hpp>

#include <iostream>
#include <csignal>
#include <vector>

#include <fc/crypto/rand.hpp>

namespace bpo = boost::program_options;
using sophiatx::protocol::version;
using std::string;
using std::vector;

string& version_string()
{
   static string v_str =
      "sophiatx_blockchain_version: " + fc::string( SOPHIATX_BLOCKCHAIN_VERSION ) + "\n" +
      "sophiatx_git_revision:       " + fc::string( sophiatx::utilities::git_revision_sha ) + "\n" +
      "fc_git_revision:          " + fc::string( fc::git_revision_sha ) + "\n";
   return v_str;
}

void info()
{
#if IS_TEST_NET
      std::cerr << "------------------------------------------------------\n\n";
      std::cerr << "            STARTING TEST NETWORK\n\n";
      std::cerr << "------------------------------------------------------\n";
      auto initminer_private_key = sophiatx::utilities::key_to_wif( SOPHIATX_INIT_PRIVATE_KEY );
      std::cerr << "initminer public key: " << SOPHIATX_INIT_PUBLIC_KEY_STR << "\n";
      std::cerr << "initminer private key: " << initminer_private_key << "\n";
      std::cerr << "blockchain version: " << fc::string( SOPHIATX_BLOCKCHAIN_VERSION ) << "\n";
      std::cerr << "------------------------------------------------------\n";
#else
      std::cerr << "------------------------------------------------------\n\n";
      std::cerr << "            STARTING SOPHIATX NETWORK\n\n";
      std::cerr << "------------------------------------------------------\n";
      std::cerr << "initminer public key: " << SOPHIATX_INIT_PUBLIC_KEY_STR << "\n";
      std::cerr << "blockchain version: " << fc::string( SOPHIATX_BLOCKCHAIN_VERSION ) << "\n";
      std::cerr << "------------------------------------------------------\n";
#endif
}

int main( int argc, char** argv )
{
   try
   {
      // Setup logging config
      bpo::options_description options;
      fc::ecc::public_key::init_cache(static_cast<uint32_t>(SOPHIATX_MAX_BLOCK_SIZE / SOPHIATX_MIN_TRANSACTION_SIZE_LIMIT), std::chrono::milliseconds(2000));

//      sophiatx::utilities::set_logging_program_options( options );
      options.add_options()
         ("backtrace", bpo::value< string >()->default_value( "yes" ), "Whether to print backtrace on SIGSEGV" );

      appbase::app_factory().add_program_options( options );

      appbase::app_factory().register_plugin_factory<sophiatx::plugins::chain::chain_plugin_full>();
      sophiatx::plugins::register_plugins();
      appbase::app_factory().set_version_string( version_string() );

      auto initialized = appbase::app_factory().initialize( argc, argv, {"chain", "p2p", "json_rpc", "webserver"} );

      info();

      if( !initialized.size() )
         return 0;

      auto& args = appbase::app_factory().global_args;

      try
      {
         // TODO: configure new logging
//         fc::optional< fc::logging_config > logging_config = sophiatx::utilities::load_logging_config( args, appbase::app_factory().data_dir );
//         if( logging_config )
//            fc::configure_logging( *logging_config );
      }
      catch( const fc::exception& )
      {
         wlog( "Error parsing logging config" );
      }

      if( args.at( "backtrace" ).as< string >() == "yes" )
      {
         fc::print_stacktrace_on_segfault();
         ilog( "Backtrace on segfault is enabled." );
      }

      appbase::app_factory().startup();
      appbase::app_factory().exec();
      std::cout << "exited cleanly\n";

      return 0;
   }
   catch ( const boost::exception& e )
   {
      std::cerr << boost::diagnostic_information(e) << "\n";
   }
   catch ( const fc::exception& e )
   {
      std::cerr << e.to_detail_string() << "\n";
   }
   catch ( const std::exception& e )
   {
      std::cerr << e.what() << "\n";
   }
   catch ( ... )
   {
      std::cerr << "unknown exception\n";
   }

   return -1;
}
