#ifndef SOPHIATX_LOGGER_HPP
#define SOPHIATX_LOGGER_HPP

#include <sophiatx/utilities/sys_logger.hpp>

namespace sophiatx { namespace utilities {

/**
 * @brief Usage sophiatx::utilities::logger().info("message to log")
 *
 * @return SysLogger&
 */
SysLogger& logger();

//#define STR(x) #x
//#define STRINGIFY(x) STR(x)
//#define LOCATION "<" __FILE__ ":" STRINGIFY(__LINE__) ">:"
//
//// Defines are used to catch file_name, row and method from which the message was logged
//#define dlog_( ... ) sophiatx::utilities::logger().debug(LOCATION, __VA_ARGS__)
//#define ilog_( ... ) sophiatx::utilities::logger().info(LOCATION, __VA_ARGS__)
//#define nlog_( ... ) sophiatx::utilities::logger().notice(LOCATION, __VA_ARGS__)
//#define wlog_( ... ) sophiatx::utilities::logger().warning(LOCATION, __VA_ARGS__)
//#define elog_( ... ) sophiatx::utilities::logger().error(LOCATION, __VA_ARGS__)
//#define clog_( ... ) sophiatx::utilities::logger().critical(LOCATION, __VA_ARGS__)
//#define alog_( ... ) sophiatx::utilities::logger().alert(LOCATION, __VA_ARGS__)
//#define emlog_( ... ) sophiatx::utilities::logger().emergency(LOCATION, __VA_ARGS__)

} }

#endif //SOPHIATX_LOGGER_HPP
