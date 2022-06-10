#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <map>
#include <string>
#include <cstring>
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

template<typename T>
struct type_identity
{
    using type = T;
};

template<typename T>
using type_identity_t = typename type_identity<T>::type;


template<typename... Ts>
struct make_void : public type_identity<void> { };

template<typename... Ts>
using void_t = typename make_void<Ts...>::type;


template<bool B, typename T>
using enable_if_t = typename std::enable_if<B, T>::type;






template<typename T>
inline constexpr auto min(const T& a, const T& b) noexcept(noexcept(a < b)) -> decltype(a < b, std::declval<const T&>())
{
    return a < b ? a : b;
}

template<typename T>
inline constexpr auto max(const T& a, const T& b) noexcept(noexcept(a < b)) -> decltype(a < b, std::declval<const T&>())
{
    return a < b ? b : a;
}


////////////////////////////////////////////////////////////////////////////////

template<typename CharT>
class basic_string_view
{
private:
    const CharT*        data_;
    std::size_t         size_;

public:
    using value_type    = CharT;
    using size_type     = std::size_t;
    using char_traits   = std::char_traits<CharT>;
    using iterator      = const CharT*;

    static constexpr size_type npos = size_type(-1);

public:
    constexpr basic_string_view() noexcept 
        : data_(nullptr), size_(0) { }

    constexpr basic_string_view(const CharT* data, size_type size) noexcept
        : data_(data), size_(size) { }

    basic_string_view(const CharT* const str) noexcept
        : data_(str), size_(char_traits::length(str)) { } 

    template<typename Traits, typename Alloc>
    basic_string_view(const std::basic_string<CharT, Traits, Alloc>& str)
        : data_(str.data()), size_(str.size()) { }



public:
    constexpr const CharT* data() const noexcept            { return data_;         }
    constexpr size_type size() const noexcept               { return size_;         }
    constexpr size_type max_size() const noexcept           { return size_type(-1); }
    constexpr bool empty() const noexcept                   { return size() == 0;   }

    constexpr iterator begin() const noexcept               { return data_;         }
    constexpr iterator end() const noexcept                 { return data_ + size_; }
    constexpr const CharT& operator[](size_type pos) const  { return data_[pos];    }


    size_type find(CharT ch, size_type pos = 0) const noexcept 
    {
        if (pos >= size()) return npos;
        auto iter = char_traits::find(data_ + pos, size_ - pos, ch);
        return iter == nullptr ? npos : iter - data_;
    }

    int compare(basic_string_view other) const noexcept
    {
        size_type str_len = min(size(), other.size());
        auto result = char_traits::compare(data_, other.data_, str_len);
        if (result == 0)
        {
            result = (size_ == other.size_ ? 0 : (size_ < other.size_ ? -1 : 1));
        }

        return result;
    }

    void remove_prefix(size_type n) noexcept
    {
        data_ += n;
        size_ -= n;
    }

    void remove_subfix(size_type n) noexcept
    {
        size_ -= n;
    }

    constexpr basic_string_view substr(size_type pos = 0, size_type count = npos) const noexcept 
    {
        return { data_ + pos, min(count, size_ - pos) };
    }


public:

    friend std::ostream& operator<<(std::ostream& os, basic_string_view str)
    {
        os.write(str.data(), str.size());
        return os;
    }

    friend bool operator==(basic_string_view lhs, basic_string_view rhs) noexcept 
    {
        return lhs.compare(rhs) == 0;
    }

    friend bool operator!=(basic_string_view lhs, basic_string_view rhs) noexcept 
    {
        return lhs.compare(rhs) != 0;
    }

    friend bool operator<(basic_string_view lhs, basic_string_view rhs) noexcept 
    {
        return lhs.compare(rhs) < 0;
    }

    friend bool operator<=(basic_string_view lhs, basic_string_view rhs) noexcept 
    {
        return lhs.compare(rhs) <= 0;
    }

    friend bool operator>(basic_string_view lhs, basic_string_view rhs) noexcept 
    {
        return lhs.compare(rhs) > 0;
    }

    friend bool operator>=(basic_string_view lhs, basic_string_view rhs) noexcept 
    {
        return lhs.compare(rhs) >= 0;
    }
};



template<typename CharT>
struct is_basic_string_view : std::false_type { };

template<typename CharT>
struct is_basic_string_view<basic_string_view<CharT>> : std::true_type { };


}   // namespace detail


////////////////////////////////////////////////////////////////////////////////

namespace detail
{

using size_type         = std::size_t;
using string_type       = std::string;
using string_view       = basic_string_view<char>;


template<typename T>
using init_list_type    = std::initializer_list<T>;

template<typename T, typename U>
using pair_type         = std::pair<T, U>;


using arg_value_type    = std::function<void(std::ostream&)>;
using arg_type          = pair_type<string_view, arg_value_type>;


}   // namespace detail



template<typename... Args>
detail::string_type format(detail::string_view fmt, Args&&... args);

detail::string_type format(detail::string_view fmt, detail::init_list_type<detail::arg_type> args_list);

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


class format_error : public std::runtime_error
{
public:
    explicit format_error(const char* msg)
        : std::runtime_error(msg) { }

    explicit format_error(const std::string& msg)
        : std::runtime_error(msg) { }
};


}   // namespace detail



namespace detail
{

template<typename CharT>
class basic_format_args
{
public:
    using char_type         = CharT;
    using value_type        = CharT;
    
    template<typename K, typename V>
    using map_type          = std::map<K, V>;

    
public:
    basic_format_args() noexcept = default;
    
    basic_format_args(const basic_format_args&) = delete;
    
    basic_format_args& operator=(const basic_format_args&) = delete;

    
    template<typename... Args>
    explicit basic_format_args(Args&&... args)
    {
        make_num_args({ arg_value(std::forward<Args>(args))... });
    }

    
    explicit basic_format_args(init_list_type<arg_type> name_args_list)
    {
        make_name_args(name_args_list);
    }


public:

    const map_type<string_view, arg_value_type>& get_args() const noexcept
    {
        return args_;
    }

    
    static string_view num_arg_id(size_type id) 
    {
        static constexpr const char arg_id[MAX_ARGS_COUNT][3]{
             "0",  "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",
            "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
            "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
            "30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
            "40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
            "50", "51", "52", "53", "54", "55", "56", "57", "58", "59",
            "60", "61", "62", "63"
        };

        if (id >= MAX_ARGS_COUNT) 
        {
            throw arg_error(format("num_arg id to big({} >= {})", id, MAX_ARGS_COUNT));
        }

        return { arg_id[id], id < 10u ? 1u : 2u };
    }

    
    template<typename T>
    static arg_value_type arg_value(const T& val)  noexcept
    {
        return [&val](std::ostream& os) { os << val; };
    }


    template<typename T>
    static arg_type num_arg(size_type num, T&& val)  noexcept
    {
        return { num_arg_id(num), arg_value(std::forward<T>(val)) };
    }


    template<typename T>
    static arg_type name_arg(const CharT* name, T&& val) noexcept
    {
        return { name, arg_value(std::forward<T>(val)) };
    }


private:

    void make_num_args(init_list_type<arg_value_type> num_args_list)
    {
        size_type i = 0;
        for (auto&& num_val : num_args_list)
        {
            args_.emplace(num_arg_id(i++), std::move(num_val));   // num arg
        }
    }


    void make_name_args(init_list_type<arg_type> name_args_list)
    {
        size_type i = 0;
        for (auto&& name_val : name_args_list)
        {
            args_.emplace(num_arg_id(i++), name_val.second);      // num  arg
            args_.emplace(std::move(name_val));                   // name arg
        }
    }

    
private:
    map_type<string_view, arg_value_type>   args_;
    
};


using format_args = basic_format_args<char>;


}   // namespace detail



template<typename... Args>
detail::string_type format(detail::string_view fmt, Args&&... args);

detail::string_type format(detail::string_view fmt, detail::init_list_type<detail::arg_type> args_list);

////////////////////////////////////////////////////////////////////////////////


namespace detail
{

    
inline char* num_buffer() noexcept
{
    constexpr size_type buffer_len = 32;
    static char buffer[buffer_len]{ 0 };

    return buffer;
}


inline size_t count_digits(unsigned int num) noexcept
{
	size_t count = 1;
	for (;;)
	{
		if (num < 10)		return count;
		if (num < 100)		return count + 1;
		if (num < 1000)		return count + 2;
		if (num < 10000)	return count + 3;
		
		num /= 10000u;
		count += 4;
	}

	return count;
}


string_view num2str(int num)
{
	static constexpr const char digits[][2]{
		{'0', '0'}, {'0', '1'}, {'0', '2'}, {'0', '3'}, {'0', '4'}, {'0', '5'}, {'0', '6'}, {'0', '7'}, {'0', '8'}, {'0', '9'},
		{'1', '0'}, {'1', '1'}, {'1', '2'}, {'1', '3'}, {'1', '4'}, {'1', '5'}, {'1', '6'}, {'1', '7'}, {'1', '8'}, {'1', '9'},
		{'2', '0'}, {'2', '1'}, {'2', '2'}, {'2', '3'}, {'2', '4'}, {'2', '5'}, {'2', '6'}, {'2', '7'}, {'2', '8'}, {'2', '9'},
		{'3', '0'}, {'3', '1'}, {'3', '2'}, {'3', '3'}, {'3', '4'}, {'3', '5'}, {'3', '6'}, {'3', '7'}, {'3', '8'}, {'3', '9'},
		{'4', '0'}, {'4', '1'}, {'4', '2'}, {'4', '3'}, {'4', '4'}, {'4', '5'}, {'4', '6'}, {'4', '7'}, {'4', '8'}, {'4', '9'},
		{'5', '0'}, {'5', '1'}, {'5', '2'}, {'5', '3'}, {'5', '4'}, {'5', '5'}, {'5', '6'}, {'5', '7'}, {'5', '8'}, {'5', '9'},
		{'6', '0'}, {'6', '1'}, {'6', '2'}, {'6', '3'}, {'6', '4'}, {'6', '5'}, {'6', '6'}, {'6', '7'}, {'6', '8'}, {'6', '9'},
		{'7', '0'}, {'7', '1'}, {'7', '2'}, {'7', '3'}, {'7', '4'}, {'7', '5'}, {'7', '6'}, {'7', '7'}, {'7', '8'}, {'7', '9'},
		{'8', '0'}, {'8', '1'}, {'8', '2'}, {'8', '3'}, {'8', '4'}, {'8', '5'}, {'8', '6'}, {'8', '7'}, {'8', '8'}, {'8', '9'},
		{'9', '0'}, {'9', '1'}, {'9', '2'}, {'9', '3'}, {'9', '4'}, {'9', '5'}, {'9', '6'}, {'9', '7'}, {'9', '8'}, {'9', '9'},
	};


    if (num == 0)
    {
        return { "0", 1 };
    }


	auto buff_ptr = num_buffer();
	const auto buff = buff_ptr;
	using unsigned_number_t = std::make_unsigned<int>::type;
	unsigned_number_t abs_num = 0;
    size_type len = 0;

	if (num < 0)
	{
		*buff_ptr = '-';
		abs_num = static_cast<unsigned_number_t>(-num);
		len = 1 + count_digits(abs_num);
	}
	else
	{
		abs_num = static_cast<unsigned_number_t>(num);
		len = count_digits(abs_num);
	}
    buff_ptr += len;


	while (abs_num >= 100)
	{
		const auto index = abs_num % 100;
		abs_num /= 100;
		*(--buff_ptr) = digits[index][1];
		*(--buff_ptr) = digits[index][0];
	}

	if (abs_num >= 10)
	{
		const auto index = abs_num;
		*(--buff_ptr) = digits[index][1];
		*(--buff_ptr) = digits[index][0];
	}
	else
	{
		*(--buff_ptr) = static_cast<char>('0' + abs_num);
	}

	return string_view(buff, len);
}


string_view num2str(float num)
{
    return std::to_string(num);
}


template<typename T, typename = void>
struct is_num2str : std::false_type { };

template<typename T>
struct is_num2str<T, void_t<decltype(num2str(std::declval<T>()))>> : std::true_type { };





inline constexpr bool is_space(char ch)noexcept
{
    return  ch == ' '  || 
            ch == '\f' || 
            ch == '\n' || 
            ch == '\r' || 
            ch == '\t';
}


inline void skip_space(string_view fmt, size_type& index)
{
    while (is_space(fmt[index]))
    {
        ++index;
    }
}


string_view parse_name(string_view fmt, size_type& index)
{
    if (fmt[index++] != '{') 
    {
        throw parse_error("parse format name args begin error");
    }

    bool is_escape = false;
    if (fmt[index] == '{')
    {
        ++index;
        is_escape = true;
    }
    skip_space(fmt, index);

    
    const auto str = fmt.data() + index;
    size_type len = 0;
    while (true)
    {
        char ch = fmt[index];
        if (is_space(ch) || ch == '}') break;

        ++len;
        ++index;
    }


    skip_space(fmt, index);    
    if (fmt[index++] != '}')
    {
        throw parse_error("parse format name args end error");
    }

    if (is_escape)
    {
        if (fmt[index++] != '}')
        {
            throw parse_error("parse format miss escape character '}'");
        }
    }

    return { str, len };
}


void format_impl(std::ostream& os, string_view fmt, const format_args& args)
{
    constexpr size_type npos = string_view::npos;
    const auto& args_map = args.get_args();
    size_type index = 0;
    size_type default_id = 0;
    while (true)
    {
        auto pos = fmt.find('{', index);
        if (pos == npos) break;
        os << fmt.substr(index, pos - index);
        
        auto arg_name = parse_name(fmt, pos);
        if (arg_name.empty())
        {
            arg_name = format_args::num_arg_id(default_id++);
        }

        auto arg_iter = args_map.find(arg_name);
        if (arg_iter == args_map.end())
        {
            throw arg_error(format("arg name({}) not found", arg_name));
        }

        arg_iter->second(os);
        index = pos;
    }
    os << fmt.substr(index);
}


string_type format_impl(string_view fmt, const format_args& args)
{
    std::ostringstream oss;
    format_impl(oss, fmt, args);
    return oss.str();
}



}   // namespace detail


////////////////////////////////////////////////////////////////////////////////

#define __NAME_ARG(x)               sx::detail::format_args::name_arg(STR(x), x)
#define NAME_ARGS(...)              { UNPACK(__NAME_ARG, __VA_ARGS__) }


template<typename... Args>
detail::string_type format(detail::string_view fmt, Args&&... args)
{
    return detail::format_impl(fmt, detail::format_args(std::forward<Args>(args)...));
}


detail::string_type format(detail::string_view fmt, detail::init_list_type<detail::arg_type> name_args_list)
{
    return detail::format_impl(fmt, detail::format_args(name_args_list));
}


template<typename... Args>
void print(std::ostream& os, detail::string_view fmt, Args&&... args)
{
    detail::format_impl(os, fmt, detail::format_args(std::forward<Args>(args)...));
}


template<typename... Args>
void print(detail::string_view fmt, Args&&... args)
{
    detail::format_impl(std::cout, fmt, detail::format_args(std::forward<Args>(args)...));
}


void print(std::ostream& os, detail::string_view fmt, detail::init_list_type<detail::arg_type> name_args_list)
{
    detail::format_impl(os, fmt, detail::format_args(name_args_list));
}


void print(detail::string_view fmt, detail::init_list_type<detail::arg_type> name_args_list)
{
    detail::format_impl(std::cout, fmt, detail::format_args(name_args_list));
}



}   // namespace sx

#endif // FORMAT_HPP