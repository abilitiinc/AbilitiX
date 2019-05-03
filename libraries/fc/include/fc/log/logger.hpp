#pragma once
#include <fc/string.hpp>
#include <fc/time.hpp>
#include <fc/shared_ptr.hpp>
#include <fc/log/log_message.hpp>
#include <sophiatx/utilities/sys_logger.hpp>

namespace fc
{

   /**
    * @brief Usage sophiatx::utilities::logger().info("message to log")
    *
    * @return SysLogger&
    */
   sophiatx::utilities::SysLogger& logger_();

   class appender;

   /**
    *
    *
    @code
      void my_class::func()
      {
         fc_dlog( my_class_logger, "Format four: ${arg}  five: ${five}", ("arg",4)("five",5) );
      }
    @endcode
    */
   class logger
   {
      public:
         static logger get( const fc::string& name = "default");

         logger();
         logger( const string& name, const logger& parent = nullptr );
         logger( std::nullptr_t );
         logger( const logger& c );
         logger( logger&& c );
         ~logger();
         logger& operator=(const logger&);
         logger& operator=(logger&&);
         friend bool operator==( const logger&, nullptr_t );
         friend bool operator!=( const logger&, nullptr_t );

         logger&    set_log_level( log_level e );
         log_level  get_log_level()const;
         logger&    set_parent( const logger& l );
         logger     get_parent()const;

         void  set_name( const fc::string& n );
         const fc::string& name()const;

         void add_appender( const fc::shared_ptr<appender>& a );
         std::vector<fc::shared_ptr<appender> > get_appenders()const;
         void remove_appender( const fc::shared_ptr<appender>& a );

         bool is_enabled( log_level e )const;
         void log( log_message m );

      private:
         class impl;
         fc::shared_ptr<impl> my;
   };

} // namespace fc

#define STR(x) #x
#define STRINGIFY(x) STR(x)
#define LOCATION "[" __FILE__ ":" STRINGIFY(__LINE__) "] --"


#define dlog( FORMAT, ... ) fc::logger_().debug( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )
#define ilog( FORMAT, ... ) fc::logger_().info( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )
#define nlog( FORMAT, ... ) fc::logger_().notice( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )
#define wlog( FORMAT, ... ) fc::logger_().warning( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )
#define elog( FORMAT, ... ) fc::logger_().error( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )
#define clog( FORMAT, ... ) fc::logger_().critical( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )
#define alog( FORMAT, ... ) fc::logger_().alert( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )
#define emlog( FORMAT, ... ) fc::logger_().emergency( LOCATION, FC_LOG_MESSAGE_( FORMAT, __VA_ARGS__ ).get_message() )


// this disables all normal logging statements -- not something you'd normally want to do,
// but it's useful if you're benchmarking something and suspect logging is causing
// a slowdown.
#ifdef FC_DISABLE_LOGGING
   # undef dlog
   # define dlog(...)
   # undef ilog
   # define ilog(...)
   # undef nlog
   # define nlog(...)
   # undef wlog
   # define wlog(...)
   # undef elog
   # define elog(...)
   # undef clog
   # define clog(...)
   # undef alog
   # define alog(...)
   # undef emlog
   # define emlog(...)
#endif



#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/punctuation/paren.hpp>


#define FC_FORMAT_ARG(r, unused, base) \
  BOOST_PP_STRINGIZE(base) ": ${" BOOST_PP_STRINGIZE( base ) "} "

#define FC_FORMAT_ARGS(r, unused, base) \
  BOOST_PP_LPAREN() BOOST_PP_STRINGIZE(base),fc::variant(base) BOOST_PP_RPAREN()

#define FC_FORMAT( SEQ )\
    BOOST_PP_SEQ_FOR_EACH( FC_FORMAT_ARG, v, SEQ )

// takes a ... instead of a SEQ arg because it can be called with an empty SEQ
// from FC_CAPTURE_AND_THROW()
#define FC_FORMAT_ARG_PARAMS( ... )\
    BOOST_PP_SEQ_FOR_EACH( FC_FORMAT_ARGS, v, __VA_ARGS__ )

#define ddump( SEQ ) \
    dlog( FC_FORMAT(SEQ), FC_FORMAT_ARG_PARAMS(SEQ) )
#define idump( SEQ ) \
    ilog( FC_FORMAT(SEQ), FC_FORMAT_ARG_PARAMS(SEQ) )
#define wdump( SEQ ) \
    wlog( FC_FORMAT(SEQ), FC_FORMAT_ARG_PARAMS(SEQ) )
#define edump( SEQ ) \
    elog( FC_FORMAT(SEQ), FC_FORMAT_ARG_PARAMS(SEQ) )
