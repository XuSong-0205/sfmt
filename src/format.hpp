#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <map>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
#include <sstream>
#include <utility>
#include <iomanip>
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
        n = min(n, size_);
        data_ += n;
        size_ -= n;
    }

    void remove_subfix(size_type n) noexcept
    {
        n = min(n, size_);
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


}   // namespace detail



template<typename... Args>
detail::string_type format(detail::string_view fmt, Args&&... args);

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

    template<typename T>
    using init_list_type    = std::initializer_list<T>;
    
    template<typename T, typename U>
    using pair_type         = std::pair<T, U>;
    
    template<typename K, typename V>
    using map_type          = std::map<K, V>;

    using arg_value_type    = std::function<void(std::ostream&)>;
    using arg_type          = pair_type<string_view, arg_value_type>;

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


using format_args    = basic_format_args<char>;
using arg_type       = format_args::arg_type;

template<typename T>
using init_list_type = format_args::init_list_type<T>;

}   // namespace detail




namespace detail
{


template<typename CharT>
class basic_format_parse
{
public:
    using value_type = CharT;
    using format_t = unsigned int;

    // 填充与对齐(可选) 符号(可选) #(可选) 0(可选) 宽度(可选) 精度(可选) 类型(可选)		
    enum class arg_format : format_t
    {
        fmt_escape = 0,     // {{}}


        fmt_fill_left,      // <    √
        fmt_fill_right,     // >    √
        // fmt_fill_center,    // ^    x


        fmt_symb_add,       // +    √
        fmt_symb_sub,       // -    √
        fmt_symb_space,     // ' '  √


        // fmt_well,           // #
        // fmt_zero,           // 0


        fmt_width,          // width
        fmt_prec,           // precision
        fmt_bool,           // bool

        // fmt_type_b,         // 0b
        // fmt_type_B,         // 0B
        fmt_type_o,         // 0o5
        fmt_type_d,         // 29
        fmt_type_x,         // 0x
        fmt_type_X,         // 0X
        fmt_type_e,         // 0.7e2
        fmt_type_E,         // 0.7E2
        fmt_type_f,         // 3.14
        // fmt_type_g,         // 3.141593
        fmt_type_p,         // 0x12345678   pointer
    };


public:
    explicit basic_format_parse(string_view fmt) noexcept 
        : fmt_(fmt),
          index_(0),
          default_id_(0),
          arg_fmts_(0),
          fill_char_(' '),
          width_(0),
          precision_(0) { }




    void clear() noexcept
    {
        index_ = 0;
        arg_name_ = string_view();

        arg_fmts_ = 0;
        fill_char_ = ' ';
        width_ = 0;
        precision_ = 0;
    }

    void set_index(size_type index) noexcept
    {
        index_ = index;
    }

    
    size_type get_index() const noexcept
    {
        return index_;
    }

    string_view get_arg_name() const noexcept 
    {
        return arg_name_;
    }

    format_t get_arg_fmts() const noexcept 
    {
        return arg_fmts_;
    }

    unsigned int get_width() const noexcept 
    {
        return width_;
    }

    unsigned int get_prec() const noexcept 
    {
        return precision_;
    }

    value_type get_fill_char() const noexcept 
    {
        return fill_char_;
    }


private:

    string_view::value_type curr_char() 
    {
        return fmt_[index_];
    }

    string_view::value_type next_char() 
    {
        return fmt_[index_++];
    }

    void forward_index() noexcept
    {
        ++index_;
    }


    static constexpr bool is_space(CharT ch) noexcept 
    {
        return  ch == ' '  || 
                ch == '\f' || 
                ch == '\n' || 
                ch == '\r' || 
                ch == '\t'; 
    }

    void skip_space()
    {
        while (is_space(curr_char()))
        {
            forward_index();
        }
    }

    void add_arg_format(arg_format arg_fmt) noexcept
    {
        arg_fmts_ |= 1 << static_cast<format_t>(arg_fmt);
    }


public:

    void parse()
    {
        if (next_char() != '{') 
        {
            throw parse_error(format("parse format begin error, \"{}\" not '{}' begin\n",
                                fmt_.substr(index_, 10), '{'));
        }

        parse_arg();

        if (next_char() != '}')
        {
            throw parse_error(format("parse format end error, '{}' not '}' end\n", curr_char()));
        }
    }


private:

    void parse_arg()
    {
        bool is_escape = false;
        if (curr_char() == '{')
        {
            forward_index();
            is_escape = true;
        }
        skip_space();


        // parse arg name
        parse_name();

        // parse arg format
        parse_format();


        skip_space();
        if (is_escape)
        {
            if (next_char() != '}')
            {
                throw parse_error("parse format miss escape character '}'");
            }

            add_arg_format(arg_format::fmt_escape);
        }
    }


    void parse_name()
    {
        const auto name = fmt_.data() + index_;
        size_type name_len = 0;
        while (true)
        {
            char ch = curr_char();
            if (is_space(ch) || ch == ':' || ch == '}') break;

            ++name_len;
            forward_index();
        }

        if (name_len > 0)
        {
            arg_name_ = string_view(name, name_len);
        }
        else
        {
            arg_name_ = format_args::num_arg_id(default_id_++);
        }
    }


    void parse_format()
    {
        if (curr_char() != ':')
        {
            return;
        }

        // skip :
        forward_index();

        // parse c</>/^
        parse_fill();

        // parse +/-/' '/#/0
        parse_symb();

        // parse width
        parse_width();

        // parse precision
        parse_prec();

        // parse b/B/o/d/x/X/e/E/f/F/g/G/p/P/s
        parse_type();

    }


    void parse_fill()
    {
        bool has_align = false;
        auto curr = curr_char();
        auto align_fmt = curr;
        if (curr == '<' || curr == '>' || curr == '^')
        {
            fill_char_ = ' ';
            has_align = true;

            forward_index();
        }
        else if (curr != '}')
        {
            auto next = fmt_[index_ + 1];
            if (next == '<' || next == '>')
            {
                fill_char_ = curr;
                has_align = true;
                align_fmt = next;

                forward_index();
                forward_index();
            }
        }

        if (has_align)
        {
            if (align_fmt == '<')
            {
                add_arg_format(arg_format::fmt_fill_left);
            }
            else if (align_fmt == '>')
            {
                add_arg_format(arg_format::fmt_fill_right);
            }
        }

    }


    void parse_symb()
    {
        switch (curr_char())
        {
        case '+':
            add_arg_format(arg_format::fmt_symb_add);
            forward_index();
            break;

        case '-':
            add_arg_format(arg_format::fmt_symb_sub);
            forward_index();
            break;

        case ' ':
            add_arg_format(arg_format::fmt_symb_space);
            forward_index();
            break;
        }
    }


    void parse_width()
    {
        unsigned int width = 0;
        while (isdigit(curr_char()))
        {
            width = width * 10 + (curr_char() - '0');
            forward_index();
        }

        if (width > 0)
        {
            width_ = width;
            add_arg_format(arg_format::fmt_width);
        }
    }


    void parse_prec()
    {
        if (curr_char() == '.')
        {
            forward_index();

            unsigned int prec = 0;
            while (isdigit(curr_char()))
            {
                prec = prec * 10 + (curr_char() - '0');
                forward_index();
            }

            if (prec > 0)
            {
                precision_ = prec;
                add_arg_format(arg_format::fmt_prec);
            }
        }
    }


    void parse_type()
    {
        switch (curr_char())
        {
        case 'b':
            add_arg_format(arg_format::fmt_bool);
            forward_index();
            break;

        case 'o':
            add_arg_format(arg_format::fmt_type_o);
            forward_index();
            break;

        case 'd':
            add_arg_format(arg_format::fmt_type_d);
            forward_index();
            break;

        case 'x':
            add_arg_format(arg_format::fmt_type_x);
            forward_index();
            break;

        case 'X':
            add_arg_format(arg_format::fmt_type_X);
            forward_index();
            break;

        case 'e':
            add_arg_format(arg_format::fmt_type_e);
            forward_index();
            break;

        case 'E':
            add_arg_format(arg_format::fmt_type_E);
            forward_index();
            break;

        case 'f':
        case 'F':
            add_arg_format(arg_format::fmt_type_f);
            forward_index();
            break;

        case 'p':
            add_arg_format(arg_format::fmt_type_p);
            forward_index();
            break;
        }
    }


private:
    string_view     fmt_;
    size_type       index_;

    size_type       default_id_;
    string_view     arg_name_;

    format_t        arg_fmts_;
    value_type      fill_char_;
    unsigned int    width_;
    unsigned int    precision_;
};

using format_parse  = basic_format_parse<char>;
using format_t      = format_parse::format_t;
using arg_format    = format_parse::arg_format;




template<typename CharT>
class basic_formatter
{
public:
    basic_formatter(string_view fmt, const format_args& args) noexcept 
        : fmt_(fmt), args_(args) { }



    string_type to_string() const
    {
        std::ostringstream oss;
        format_impl(oss);
        return oss.str();
    }

    void to_ostream(std::ostream& os) const
    {
        format_impl(os);
    }

    void to_file(std::FILE* file) const
    {
        // todo
    }


private:
    void format_impl(std::ostream& os) const
    {
        constexpr size_type npos = string_view::npos;
        const auto& args_map = args_.get_args();
        size_type index = 0;
        format_parse fmt_parse(fmt_);

        while (true)
        {
            auto pos = fmt_.find('{', index);
            if (pos == npos) break;
            os << fmt_.substr(index, pos - index);
            
            fmt_parse.clear();
            fmt_parse.set_index(pos);
            fmt_parse.parse();

            auto arg_name = fmt_parse.get_arg_name();
            auto arg_iter = args_map.find(arg_name);
            if (arg_iter == args_map.end())
            {
                throw arg_error(format("arg name({}) not found", arg_name));
            }

            to_format(os, fmt_parse, *arg_iter);

            index = fmt_parse.get_index();
        }

        os << fmt_.substr(index);
    }


    bool has_arg_fmt(format_t fmts, arg_format arg_fmt) const
    {
        return (fmts & (1 << static_cast<format_t>(arg_fmt))) != 0;
    }


    void to_format(std::ostream& os, const format_parse& fmt_parse, const arg_type& arg) const
    {
        auto fmts = fmt_parse.get_arg_fmts();

        if (has_arg_fmt(fmts, arg_format::fmt_escape))
        {
            os.write("{", 1);
        }


        if (has_arg_fmt(fmts, arg_format::fmt_fill_left))
        {
            os << std::setfill(fmt_parse.get_fill_char()) << std::left;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_fill_right))
        {
            os << std::setfill(fmt_parse.get_fill_char()) << std::right;
        }


        if (has_arg_fmt(fmts, arg_format::fmt_symb_add))
        {
            os << std::showpos;
        }
        
        if (has_arg_fmt(fmts, arg_format::fmt_symb_sub))
        {
            os << std::noshowpos;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_symb_space))
        {
            // todo
            os << std::noshowpos;
        }



        if (has_arg_fmt(fmts, arg_format::fmt_width))
        {
            os << std::setfill(fmt_parse.get_fill_char()) <<  std::setw(fmt_parse.get_width());
        }

        if (has_arg_fmt(fmts, arg_format::fmt_prec))
        {
            os << std::setprecision(fmt_parse.get_prec());
        }


        if (has_arg_fmt(fmts, arg_format::fmt_bool))
        {
            os << std::boolalpha;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_o))
        {
            os << std::showbase << std::oct;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_d))
        {
            os << std::showbase << std::dec;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_x))
        {
            os << std::showbase << std::hex << std::nouppercase;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_X))
        {
            os << std::showbase << std::hex << std::uppercase;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_e))
        {
            os << std::showbase << std::scientific  << std::nouppercase;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_E))
        {
            os << std::showbase << std::scientific << std::uppercase;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_f))
        {
            os << std::showbase << std::fixed;
        }

        if (has_arg_fmt(fmts, arg_format::fmt_type_p))
        {
            os << std::showbase << std::hex  << std::nouppercase;
        }


        arg.second(os);


        if (has_arg_fmt(fmts, arg_format::fmt_escape))
        {
            os.write("}", 1);
        }

    }


private:
    string_view         fmt_;
    const format_args&  args_;

};


using formatter = basic_formatter<char>;




static string_type vformat(string_view fmt, const format_args& args)
{
    return formatter(fmt, args).to_string();
}

static void vformat(std::ostream& os, string_view fmt, const format_args& args)
{
    formatter(fmt, args).to_ostream(os);
}



}   // namespace detail


////////////////////////////////////////////////////////////////////////////////

#define __NAME_ARG(x)               sx::detail::format_args::name_arg(STR(x), x)
#define NAME_ARGS(...)              { UNPACK(__NAME_ARG, __VA_ARGS__) }


template<typename... Args>
detail::string_type format(detail::string_view fmt, Args&&... args)
{
    return detail::vformat(fmt, detail::format_args(std::forward<Args>(args)...));
}


detail::string_type format(detail::string_view fmt, detail::init_list_type<detail::arg_type> name_args_list)
{
    return detail::vformat(fmt, detail::format_args(name_args_list));
}


template<typename... Args>
void print(std::ostream& os, detail::string_view fmt, Args&&... args)
{
    detail::vformat(os, fmt, detail::format_args(std::forward<Args>(args)...));
}


template<typename... Args>
void print(detail::string_view fmt, Args&&... args)
{
    detail::vformat(std::cout, fmt, detail::format_args(std::forward<Args>(args)...));
}


void print(std::ostream& os, detail::string_view fmt, detail::init_list_type<detail::arg_type> name_args_list)
{
    detail::vformat(os, fmt, detail::format_args(name_args_list));
}


void print(detail::string_view fmt, detail::init_list_type<detail::arg_type> name_args_list)
{
    detail::vformat(std::cout, fmt, detail::format_args(name_args_list));
}



}   // namespace sx

#endif // FORMAT_HPP