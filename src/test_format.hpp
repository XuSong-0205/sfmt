#ifndef TEST_FORMAT_HPP
#define TEST_FORMAT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <initializer_list>
#include <stdexcept>
#include <thread>
#include <ctime>
#include <iomanip>


namespace mini
{

namespace detail
{


using arg_builder_t = std::function<void(std::ostream&)>;


template<typename Arg>
arg_builder_t format_arg(Arg&& arg)
{
    return [&arg](std::ostream& os){ os << arg; };
}


std::string format_impl(const std::string& fmt, std::initializer_list<arg_builder_t> fmt_args)
{
    std::ostringstream oss;
    size_t index = 0;
    auto iter = fmt_args.begin();
    const auto iter_end = fmt_args.end();
    while (index != std::string::npos)
    {
        auto pos = fmt.find("{}", index);
        if (pos == std::string::npos) break;
        if (iter == iter_end) throw std::runtime_error("Insufficient number of parameters!");

        oss << fmt.substr(index, pos - index);
        (*(iter++))(oss);
        index = pos + 2;
    }
    oss << fmt.substr(index);

    return oss.str();
}


std::string format_impl(std::initializer_list<arg_builder_t> fmt_args, char dem = ' ')
{
    std::ostringstream oss;
    size_t i = 0;
    size_t fmt_len = fmt_args.size();
    for (auto&& func : fmt_args)
    {
        func(oss);
        if (++i != fmt_len) oss << dem;
    }

    return oss.str();
}

}   // namespace detail


template<typename... Args>
std::string format(const std::string& fmt, Args&&... args)
{
    return detail::format_impl(fmt, { detail::format_arg(std::forward<Args>(args))... });
}


template<typename... Args>
void print(const std::string& fmt, Args&&... args)
{
    std::cout << format(fmt, std::forward<Args>(args)...);
}



}   // namespace sx


namespace log
{


enum class log_level : int
{
    FATAL,
    ERROR,
    WRAN,
    DEBUG,
    INFO,
};


std::ostream& operator<<(std::ostream& os, log_level level)
{
    static constexpr char level_name[][6]{
        "FATAL",
        "ERROR",
        "WRAN ",
        "DEBUG",
        "INFO "
    };

    return os << level_name[static_cast<int>(level)];
}


template<typename... Args>
std::string log_impl(log_level level, Args&&... args)
{
    const auto now = time(nullptr);
    return  mini::format("[{}] [{}] [{}]: {}\n",
                        std::put_time(localtime(&now), "%Y-%m-%d %H:%M:%S"), 
                        std::this_thread::get_id(),
                        level,
                        mini::detail::format_impl({ mini::detail::format_arg(std::forward<Args>(args))... }).c_str());
}


template<typename... Args>
void log(std::ostream& os, log_level level, Args&&... args)
{
    os << log_impl(level, std::forward<Args>(args)...);
}


template<typename... Args>
void log(log_level level, Args&&... args)
{
    log(std::cout, level, std::forward<Args>(args)...);
}


#define LOG(...)            log::log(__VA_ARGS__)
#define LOG_FATAL(...)      log::log(log::log_level::FATAL, __VA_ARGS__)
#define LOG_ERROR(...)      log::log(log::log_level::ERROR, __VA_ARGS__)
#define LOG_WRAN(...)       log::log(log::log_level::WRAN,  __VA_ARGS__)
#define LOG_DEBUG(...)      log::log(log::log_level::DEBUG, __VA_ARGS__)
#define LOG_INFO(...)       log::log(log::log_level::INFO,  __VA_ARGS__)


}   // namespace log


#endif // TEST_FORMAT_HPP