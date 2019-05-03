#include <fc/log/logger.hpp>

namespace fc {

sophiatx::utilities::SysLogger& logger_() {
   static sophiatx::utilities::SysLogger sophiatxd_logger("sophiatx");
   return sophiatxd_logger;
}

} // namespace fc
