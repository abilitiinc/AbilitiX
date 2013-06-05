#include <fc/asio.hpp>
#include <fc/network/ip.hpp>

namespace fc
{
  fc::vector<fc::ip::endpoint> resolve( const fc::string& host, uint16_t port )
  {
    auto ep = fc::asio::tcp::resolve( host, std::to_string(uint64_t(port)) );
    fc::vector<fc::ip::endpoint> eps;
    eps.reserve(ep.size());
    for( auto itr = ep.begin(); itr != ep.end(); ++itr )
      eps.push_back( fc::ip::endpoint(itr->address().to_v4().to_ulong(), itr->port()) );
    return eps;
  }
}
