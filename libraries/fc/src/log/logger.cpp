#include <fc/log/logger.hpp>
#include <fc/exception/exception.hpp>

namespace fc {
std::unique_ptr<sophiatx::utilities::SysLogger> Logger::logger_ = nullptr;


void Logger::init(const std::string& app_name, uint log_level) {
   logger_ = std::make_unique<sophiatx::utilities::SysLogger>(app_name, log_level);
}

const std::unique_ptr<sophiatx::utilities::SysLogger>& Logger::get_instance() {
   if (logger_ == nullptr) {
      FC_THROW("fc::Logger::init(...) must be called before fc::Logger::get_instance()");
   }

   return logger_;
}

} // namespace fc
