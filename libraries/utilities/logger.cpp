#include <sophiatx/utilities/logger.hpp>

namespace sophiatx { namespace utilities {

SysLogger& logger() {
   static SysLogger sophiatxd_logger("test");

   return sophiatxd_logger;
}

} }
