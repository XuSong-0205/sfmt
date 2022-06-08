#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <type_traits>
#include <initializer_list>



namespace sx
{

#define ARG(x)											        x

#define ARGN(_1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9,  _10,  \
             _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,  \
             _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,  \
             _31, _32, _33, _34, _35, _36, _37, _38, _39, _40,  \
             _41, _42, _43, _44, _45, _46, _47, _48, _49, _50,  \
             _51, _52, _53, _54, _55, _56, _57, _58, _59, _60,  \
             _61, _62, _63, _64, N, ...)		                N
  
#define ARGS_COUNT(...)                                         \
ARG(ARGN(__VA_ARGS__,               64, 63, 62, 61,             \
            60, 59, 58, 57, 56, 55, 54, 53, 52, 51,             \
            50, 49, 48, 47, 46, 45, 44, 43, 42, 41,             \
            40, 39, 38, 37, 36, 35, 34, 33, 32, 31,             \
            30, 29, 28, 27, 26, 25, 24, 23, 22, 21,             \
            20, 19, 18, 17, 16, 15, 14, 13, 12, 11,             \
            10,  9,  8,  7,  6,  5,  4,  3,  2,  1))            \


#define MAX_ARGS_COUNT          64


#define __STR(s)                #s
#define STR(s)                  __STR(s)


#define __CAT(a, b)             a ## b
#define CAT(a, b)               __CAT(a, b)



#define UNPACK_1(OPT,  x, ...)      OPT(x)
#define UNPACK_2(OPT,  x, ...)      OPT(x), UNPACK_1(OPT,  __VA_ARGS__)
#define UNPACK_3(OPT,  x, ...)      OPT(x), UNPACK_2(OPT,  __VA_ARGS__)
#define UNPACK_4(OPT,  x, ...)      OPT(x), UNPACK_3(OPT,  __VA_ARGS__)
#define UNPACK_5(OPT,  x, ...)      OPT(x), UNPACK_4(OPT,  __VA_ARGS__)
#define UNPACK_6(OPT,  x, ...)      OPT(x), UNPACK_5(OPT,  __VA_ARGS__)
#define UNPACK_7(OPT,  x, ...)      OPT(x), UNPACK_6(OPT,  __VA_ARGS__)
#define UNPACK_8(OPT,  x, ...)      OPT(x), UNPACK_7(OPT,  __VA_ARGS__)
#define UNPACK_9(OPT,  x, ...)      OPT(x), UNPACK_8(OPT,  __VA_ARGS__)
#define UNPACK_10(OPT, x, ...)      OPT(x), UNPACK_9(OPT,  __VA_ARGS__)
#define UNPACK_11(OPT, x, ...)      OPT(x), UNPACK_10(OPT, __VA_ARGS__)
#define UNPACK_12(OPT, x, ...)      OPT(x), UNPACK_11(OPT, __VA_ARGS__)
#define UNPACK_13(OPT, x, ...)      OPT(x), UNPACK_12(OPT, __VA_ARGS__)
#define UNPACK_14(OPT, x, ...)      OPT(x), UNPACK_13(OPT, __VA_ARGS__)
#define UNPACK_15(OPT, x, ...)      OPT(x), UNPACK_14(OPT, __VA_ARGS__)
#define UNPACK_16(OPT, x, ...)      OPT(x), UNPACK_15(OPT, __VA_ARGS__)
#define UNPACK_17(OPT, x, ...)      OPT(x), UNPACK_16(OPT, __VA_ARGS__)
#define UNPACK_18(OPT, x, ...)      OPT(x), UNPACK_17(OPT, __VA_ARGS__)
#define UNPACK_19(OPT, x, ...)      OPT(x), UNPACK_18(OPT, __VA_ARGS__)
#define UNPACK_20(OPT, x, ...)      OPT(x), UNPACK_19(OPT, __VA_ARGS__)
#define UNPACK_21(OPT, x, ...)      OPT(x), UNPACK_20(OPT, __VA_ARGS__)
#define UNPACK_22(OPT, x, ...)      OPT(x), UNPACK_21(OPT, __VA_ARGS__)
#define UNPACK_23(OPT, x, ...)      OPT(x), UNPACK_22(OPT, __VA_ARGS__)
#define UNPACK_24(OPT, x, ...)      OPT(x), UNPACK_23(OPT, __VA_ARGS__)
#define UNPACK_25(OPT, x, ...)      OPT(x), UNPACK_24(OPT, __VA_ARGS__)
#define UNPACK_26(OPT, x, ...)      OPT(x), UNPACK_25(OPT, __VA_ARGS__)
#define UNPACK_27(OPT, x, ...)      OPT(x), UNPACK_26(OPT, __VA_ARGS__)
#define UNPACK_28(OPT, x, ...)      OPT(x), UNPACK_27(OPT, __VA_ARGS__)
#define UNPACK_29(OPT, x, ...)      OPT(x), UNPACK_28(OPT, __VA_ARGS__)
#define UNPACK_30(OPT, x, ...)      OPT(x), UNPACK_29(OPT, __VA_ARGS__)
#define UNPACK_31(OPT, x, ...)      OPT(x), UNPACK_30(OPT, __VA_ARGS__)
#define UNPACK_32(OPT, x, ...)      OPT(x), UNPACK_31(OPT, __VA_ARGS__)
#define UNPACK_33(OPT, x, ...)      OPT(x), UNPACK_32(OPT, __VA_ARGS__)
#define UNPACK_34(OPT, x, ...)      OPT(x), UNPACK_33(OPT, __VA_ARGS__)
#define UNPACK_35(OPT, x, ...)      OPT(x), UNPACK_34(OPT, __VA_ARGS__)
#define UNPACK_36(OPT, x, ...)      OPT(x), UNPACK_35(OPT, __VA_ARGS__)
#define UNPACK_37(OPT, x, ...)      OPT(x), UNPACK_36(OPT, __VA_ARGS__)
#define UNPACK_38(OPT, x, ...)      OPT(x), UNPACK_37(OPT, __VA_ARGS__)
#define UNPACK_39(OPT, x, ...)      OPT(x), UNPACK_38(OPT, __VA_ARGS__)
#define UNPACK_40(OPT, x, ...)      OPT(x), UNPACK_39(OPT, __VA_ARGS__)
#define UNPACK_41(OPT, x, ...)      OPT(x), UNPACK_40(OPT, __VA_ARGS__)
#define UNPACK_42(OPT, x, ...)      OPT(x), UNPACK_41(OPT, __VA_ARGS__)
#define UNPACK_43(OPT, x, ...)      OPT(x), UNPACK_42(OPT, __VA_ARGS__)
#define UNPACK_44(OPT, x, ...)      OPT(x), UNPACK_43(OPT, __VA_ARGS__)
#define UNPACK_45(OPT, x, ...)      OPT(x), UNPACK_44(OPT, __VA_ARGS__)
#define UNPACK_46(OPT, x, ...)      OPT(x), UNPACK_45(OPT, __VA_ARGS__)
#define UNPACK_47(OPT, x, ...)      OPT(x), UNPACK_46(OPT, __VA_ARGS__)
#define UNPACK_48(OPT, x, ...)      OPT(x), UNPACK_47(OPT, __VA_ARGS__)
#define UNPACK_49(OPT, x, ...)      OPT(x), UNPACK_48(OPT, __VA_ARGS__)
#define UNPACK_50(OPT, x, ...)      OPT(x), UNPACK_49(OPT, __VA_ARGS__)
#define UNPACK_51(OPT, x, ...)      OPT(x), UNPACK_50(OPT, __VA_ARGS__)
#define UNPACK_52(OPT, x, ...)      OPT(x), UNPACK_51(OPT, __VA_ARGS__)
#define UNPACK_53(OPT, x, ...)      OPT(x), UNPACK_52(OPT, __VA_ARGS__)
#define UNPACK_54(OPT, x, ...)      OPT(x), UNPACK_53(OPT, __VA_ARGS__)
#define UNPACK_55(OPT, x, ...)      OPT(x), UNPACK_54(OPT, __VA_ARGS__)
#define UNPACK_56(OPT, x, ...)      OPT(x), UNPACK_55(OPT, __VA_ARGS__)
#define UNPACK_57(OPT, x, ...)      OPT(x), UNPACK_56(OPT, __VA_ARGS__)
#define UNPACK_58(OPT, x, ...)      OPT(x), UNPACK_57(OPT, __VA_ARGS__)
#define UNPACK_59(OPT, x, ...)      OPT(x), UNPACK_58(OPT, __VA_ARGS__)
#define UNPACK_60(OPT, x, ...)      OPT(x), UNPACK_59(OPT, __VA_ARGS__)
#define UNPACK_61(OPT, x, ...)      OPT(x), UNPACK_60(OPT, __VA_ARGS__)
#define UNPACK_62(OPT, x, ...)      OPT(x), UNPACK_61(OPT, __VA_ARGS__)
#define UNPACK_63(OPT, x, ...)      OPT(x), UNPACK_62(OPT, __VA_ARGS__)
#define UNPACK_64(OPT, x, ...)      OPT(x), UNPACK_63(OPT, __VA_ARGS__)

#define UNPACK_X( OPT,    ...)      CAT(UNPACK_, ARGS_COUNT(__VA_ARGS__))(OPT, __VA_ARGS__)
#define UNPACK(   OPT,    ...)      UNPACK_X(OPT, __VA_ARGS__)


#define MAX_UNPACK_LEN              MAX_ARGS_COUNT


#define TO_STRING(...)              UNPACK(STR, __VA_ARGS__)
#define MAKE_STR(...)               UNPACK(STR, __VA_ARGS__)


////////////////////////////////////////////////////////////////////////////////

namespace detail
{

using size_type = std::size_t;
using string_type = std::string;

template<typename T>
using vector_type = std::vector<T>;

template<typename T>
using init_list_type = std::initializer_list<T>;

template<typename T, typename U>
using pair_type = std::pair<T, U>;

template<typename K, typename V>
using map_type = std::map<K, V>;


using arg_value_type = std::function<void(std::ostream&)>;
using arg_type = pair_type<string_type, arg_value_type>;


}   // namespace detail



template<typename... Args>
detail::string_type format(const detail::string_type& fmt, Args&&... args);

detail::string_type format(const detail::string_type& fmt, detail::init_list_type<detail::arg_type> args_list);


////////////////////////////////////////////////////////////////////////////////

namespace detail
{

class parse_error : public std::runtime_error
{
public:
    explicit parse_error(const char* msg)
        : std::runtime_error(msg) { }

    explicit parse_error(const std::string& msg)
        : std::runtime_error(msg) { }
};


class arg_error : public std::runtime_error
{
public:
    explicit arg_error(const char* msg)
        : std::runtime_error(msg) { }

    explicit arg_error(const std::string& msg)
        : std::runtime_error(msg) { }
};




constexpr bool is_space(char ch)noexcept
{
    return  ch == ' '  || 
            ch == '\f' || 
            ch == '\n' || 
            ch == '\r' || 
            ch == '\t';
}


void skip_space(const string_type& fmt, size_type& index)
{
    while (is_space(fmt[index]))
    {
        ++index;
    }
}


string_type parse_name(const string_type& fmt, size_type& index)
{
    if (fmt[index++] != '{') 
    {
        throw parse_error("parse format name args begin error");
    }
    skip_space(fmt, index);


    string_type name;
    while (true)
    {
        char ch = fmt[index];
        if (is_space(ch) || ch == '}') break;

        name.push_back(ch);
        ++index;
    }


    skip_space(fmt, index);
    if (fmt[index++] != '}')
    {
        throw parse_error("parse format name args end error");
    }

    return name;
}


string_type format_impl(const string_type& fmt, const map_type<string_type, arg_value_type>& args_name)
{
    constexpr size_type npos = std::string::npos;
    std::ostringstream oss;
    size_type index = 0;
    int default_id = 0;
    while (true)
    {
        auto pos = fmt.find('{', index);
        if (pos == npos) break;
        oss << fmt.substr(index, pos - index);
        
        auto arg_name = parse_name(fmt, pos);
        if (arg_name.empty())
        {
            arg_name = std::to_string(default_id++);
        }

        auto arg_iter = args_name.find(arg_name);
        if (arg_iter == args_name.end())
        {
            throw arg_error(format("arg name({}) not found", arg_name));
        }

        arg_iter->second(oss);
        index = pos;
    }
    oss << fmt.substr(index);

    return oss.str();
}




template<typename T>
arg_value_type arg_value(const T& val)
{
    return [&val](std::ostream& os) { os << val; };
}


template<typename T>
arg_type num_arg(size_type index, T&& val)
{
    return { std::to_string(index), arg_value(std::forward<T>(val)) };
}


template<typename T, typename CharT = char>
arg_type name_arg(const CharT* name, const T& val)
{
    return { name, arg_value(val) };
}


vector_type<arg_type> make_num_args(init_list_type<arg_value_type> args_value_list)
{
    size_type i = 0;
    vector_type<arg_type> ans(args_value_list.size());
    for (auto&& val : args_value_list)
    {
        ans[i] = std::make_pair(std::to_string(i++), std::move(val));
    }

    return ans;
}


map_type<string_type, arg_value_type> make_num_args_map(init_list_type<arg_value_type> num_args_list)
{
    map_type<string_type, arg_value_type> ans;
    size_type i = 0;
    for (auto&& num_val : num_args_list)
    {
        ans.emplace(std::to_string(i++), std::move(num_val));
    }

    return ans;
}


map_type<string_type, arg_value_type> make_name_args_map(init_list_type<arg_type> name_args_list)
{
    map_type<string_type, arg_value_type> ans;
    size_type i = 0;
    for (auto&& name_val : name_args_list)
    {
        ans.emplace(std::to_string(i++), name_val.second);  // 位置参数
        ans.emplace(std::move(name_val));                   // 名字参数
    }

    return ans;
}


}   // namespace detail


////////////////////////////////////////////////////////////////////////////////

#define __NAME_ARG(x)               sx::detail::name_arg(STR(x), x)
#define NAME_ARGS(...)              { UNPACK(__NAME_ARG, __VA_ARGS__) }


template<typename... Args>
detail::string_type format(const detail::string_type& fmt, Args&&... args)
{
    return detail::format_impl(fmt, detail::make_num_args_map({ detail::arg_value(std::forward<Args>(args))... }));
}


detail::string_type format(const detail::string_type& fmt, detail::init_list_type<detail::arg_type> name_args_list)
{
    return detail::format_impl(fmt, detail::make_name_args_map(name_args_list));
}


}   // namespace sx

#endif // FORMAT_HPP