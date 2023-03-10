#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <map>              // map
#include <cstdio>           // FILE
#include <cctype>           // isdigit
#include <string>           // string
#include <sstream>          // ostringstream
#include <utility>          // pair
#include <iomanip>          // setw
#include <iostream>         // ostream
#include <stdexcept>        // runtime_error
#include <functional>       // function
#include <type_traits>      // false_type, true_type, integral_constant...
#include <initializer_list> // initializer_list


#if defined(__GNUC__) || defined(__clang__)
#   define SFMT_CPLUSPLUS   __cplusplus
#elif defined(_MSC_VER)
#   define SFMT_CPLUSPLUS   _MSVC_LANG
#endif


#if SFMT_CPLUSPLUS >= 201703L
#   include <string_view>   // std::string_view
#   define __HAS_CXX17    1
#endif




namespace sfmt
{

// macro function
namespace detail
{

#define ARG(x)                                                  x

#define ARGN(_1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9,  _10,  \
             _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,  \
             _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,  \
             _31, _32, _33, _34, _35, _36, _37, _38, _39, _40,  \
             _41, _42, _43, _44, _45, _46, _47, _48, _49, _50,  \
             _51, _52, _53, _54, _55, _56, _57, _58, _59, _60,  \
             _61, _62, _63, _64, N, ...)                        N
  
#define ARGS_COUNT(...)                                         \
ARG(ARGN(__VA_ARGS__,               64, 63, 62, 61,             \
            60, 59, 58, 57, 56, 55, 54, 53, 52, 51,             \
            50, 49, 48, 47, 46, 45, 44, 43, 42, 41,             \
            40, 39, 38, 37, 36, 35, 34, 33, 32, 31,             \
            30, 29, 28, 27, 26, 25, 24, 23, 22, 21,             \
            20, 19, 18, 17, 16, 15, 14, 13, 12, 11,             \
            10,  9,  8,  7,  6,  5,  4,  3,  2,  1))            \


#define MAX_ARGS_COUNT              64


#define __STR(s)                    #s
#define STR(s)                      __STR(s)


#define __CAT(a, b)                 a ## b
#define CAT(a, b)                   __CAT(a, b)



#define UNPACK_1(OPT,  x, ...)      OPT(x)
#define UNPACK_2(OPT,  x, ...)      OPT(x), ARG(UNPACK_1(OPT,  __VA_ARGS__))
#define UNPACK_3(OPT,  x, ...)      OPT(x), ARG(UNPACK_2(OPT,  __VA_ARGS__))
#define UNPACK_4(OPT,  x, ...)      OPT(x), ARG(UNPACK_3(OPT,  __VA_ARGS__))
#define UNPACK_5(OPT,  x, ...)      OPT(x), ARG(UNPACK_4(OPT,  __VA_ARGS__))
#define UNPACK_6(OPT,  x, ...)      OPT(x), ARG(UNPACK_5(OPT,  __VA_ARGS__))
#define UNPACK_7(OPT,  x, ...)      OPT(x), ARG(UNPACK_6(OPT,  __VA_ARGS__))
#define UNPACK_8(OPT,  x, ...)      OPT(x), ARG(UNPACK_7(OPT,  __VA_ARGS__))
#define UNPACK_9(OPT,  x, ...)      OPT(x), ARG(UNPACK_8(OPT,  __VA_ARGS__))
#define UNPACK_10(OPT, x, ...)      OPT(x), ARG(UNPACK_9(OPT,  __VA_ARGS__))
#define UNPACK_11(OPT, x, ...)      OPT(x), ARG(UNPACK_10(OPT, __VA_ARGS__))
#define UNPACK_12(OPT, x, ...)      OPT(x), ARG(UNPACK_11(OPT, __VA_ARGS__))
#define UNPACK_13(OPT, x, ...)      OPT(x), ARG(UNPACK_12(OPT, __VA_ARGS__))
#define UNPACK_14(OPT, x, ...)      OPT(x), ARG(UNPACK_13(OPT, __VA_ARGS__))
#define UNPACK_15(OPT, x, ...)      OPT(x), ARG(UNPACK_14(OPT, __VA_ARGS__))
#define UNPACK_16(OPT, x, ...)      OPT(x), ARG(UNPACK_15(OPT, __VA_ARGS__))
#define UNPACK_17(OPT, x, ...)      OPT(x), ARG(UNPACK_16(OPT, __VA_ARGS__))
#define UNPACK_18(OPT, x, ...)      OPT(x), ARG(UNPACK_17(OPT, __VA_ARGS__))
#define UNPACK_19(OPT, x, ...)      OPT(x), ARG(UNPACK_18(OPT, __VA_ARGS__))
#define UNPACK_20(OPT, x, ...)      OPT(x), ARG(UNPACK_19(OPT, __VA_ARGS__))
#define UNPACK_21(OPT, x, ...)      OPT(x), ARG(UNPACK_20(OPT, __VA_ARGS__))
#define UNPACK_22(OPT, x, ...)      OPT(x), ARG(UNPACK_21(OPT, __VA_ARGS__))
#define UNPACK_23(OPT, x, ...)      OPT(x), ARG(UNPACK_22(OPT, __VA_ARGS__))
#define UNPACK_24(OPT, x, ...)      OPT(x), ARG(UNPACK_23(OPT, __VA_ARGS__))
#define UNPACK_25(OPT, x, ...)      OPT(x), ARG(UNPACK_24(OPT, __VA_ARGS__))
#define UNPACK_26(OPT, x, ...)      OPT(x), ARG(UNPACK_25(OPT, __VA_ARGS__))
#define UNPACK_27(OPT, x, ...)      OPT(x), ARG(UNPACK_26(OPT, __VA_ARGS__))
#define UNPACK_28(OPT, x, ...)      OPT(x), ARG(UNPACK_27(OPT, __VA_ARGS__))
#define UNPACK_29(OPT, x, ...)      OPT(x), ARG(UNPACK_28(OPT, __VA_ARGS__))
#define UNPACK_30(OPT, x, ...)      OPT(x), ARG(UNPACK_29(OPT, __VA_ARGS__))
#define UNPACK_31(OPT, x, ...)      OPT(x), ARG(UNPACK_30(OPT, __VA_ARGS__))
#define UNPACK_32(OPT, x, ...)      OPT(x), ARG(UNPACK_31(OPT, __VA_ARGS__))
#define UNPACK_33(OPT, x, ...)      OPT(x), ARG(UNPACK_32(OPT, __VA_ARGS__))
#define UNPACK_34(OPT, x, ...)      OPT(x), ARG(UNPACK_33(OPT, __VA_ARGS__))
#define UNPACK_35(OPT, x, ...)      OPT(x), ARG(UNPACK_34(OPT, __VA_ARGS__))
#define UNPACK_36(OPT, x, ...)      OPT(x), ARG(UNPACK_35(OPT, __VA_ARGS__))
#define UNPACK_37(OPT, x, ...)      OPT(x), ARG(UNPACK_36(OPT, __VA_ARGS__))
#define UNPACK_38(OPT, x, ...)      OPT(x), ARG(UNPACK_37(OPT, __VA_ARGS__))
#define UNPACK_39(OPT, x, ...)      OPT(x), ARG(UNPACK_38(OPT, __VA_ARGS__))
#define UNPACK_40(OPT, x, ...)      OPT(x), ARG(UNPACK_39(OPT, __VA_ARGS__))
#define UNPACK_41(OPT, x, ...)      OPT(x), ARG(UNPACK_40(OPT, __VA_ARGS__))
#define UNPACK_42(OPT, x, ...)      OPT(x), ARG(UNPACK_41(OPT, __VA_ARGS__))
#define UNPACK_43(OPT, x, ...)      OPT(x), ARG(UNPACK_42(OPT, __VA_ARGS__))
#define UNPACK_44(OPT, x, ...)      OPT(x), ARG(UNPACK_43(OPT, __VA_ARGS__))
#define UNPACK_45(OPT, x, ...)      OPT(x), ARG(UNPACK_44(OPT, __VA_ARGS__))
#define UNPACK_46(OPT, x, ...)      OPT(x), ARG(UNPACK_45(OPT, __VA_ARGS__))
#define UNPACK_47(OPT, x, ...)      OPT(x), ARG(UNPACK_46(OPT, __VA_ARGS__))
#define UNPACK_48(OPT, x, ...)      OPT(x), ARG(UNPACK_47(OPT, __VA_ARGS__))
#define UNPACK_49(OPT, x, ...)      OPT(x), ARG(UNPACK_48(OPT, __VA_ARGS__))
#define UNPACK_50(OPT, x, ...)      OPT(x), ARG(UNPACK_49(OPT, __VA_ARGS__))
#define UNPACK_51(OPT, x, ...)      OPT(x), ARG(UNPACK_50(OPT, __VA_ARGS__))
#define UNPACK_52(OPT, x, ...)      OPT(x), ARG(UNPACK_51(OPT, __VA_ARGS__))
#define UNPACK_53(OPT, x, ...)      OPT(x), ARG(UNPACK_52(OPT, __VA_ARGS__))
#define UNPACK_54(OPT, x, ...)      OPT(x), ARG(UNPACK_53(OPT, __VA_ARGS__))
#define UNPACK_55(OPT, x, ...)      OPT(x), ARG(UNPACK_54(OPT, __VA_ARGS__))
#define UNPACK_56(OPT, x, ...)      OPT(x), ARG(UNPACK_55(OPT, __VA_ARGS__))
#define UNPACK_57(OPT, x, ...)      OPT(x), ARG(UNPACK_56(OPT, __VA_ARGS__))
#define UNPACK_58(OPT, x, ...)      OPT(x), ARG(UNPACK_57(OPT, __VA_ARGS__))
#define UNPACK_59(OPT, x, ...)      OPT(x), ARG(UNPACK_58(OPT, __VA_ARGS__))
#define UNPACK_60(OPT, x, ...)      OPT(x), ARG(UNPACK_59(OPT, __VA_ARGS__))
#define UNPACK_61(OPT, x, ...)      OPT(x), ARG(UNPACK_60(OPT, __VA_ARGS__))
#define UNPACK_62(OPT, x, ...)      OPT(x), ARG(UNPACK_61(OPT, __VA_ARGS__))
#define UNPACK_63(OPT, x, ...)      OPT(x), ARG(UNPACK_62(OPT, __VA_ARGS__))
#define UNPACK_64(OPT, x, ...)      OPT(x), ARG(UNPACK_63(OPT, __VA_ARGS__))

#define UNPACK_X( OPT,    ...)      ARG(CAT(UNPACK_, ARGS_COUNT(__VA_ARGS__))(OPT, __VA_ARGS__))
#define UNPACK(   OPT,    ...)      UNPACK_X(OPT, __VA_ARGS__)


#define MAX_UNPACK_LEN              MAX_ARGS_COUNT


}   // namespace detail




////////////////////////////////////////////////////////////////////////////////

// template meta function
namespace detail
{

template<typename T>
struct type_identity
{
    using type = T;
};

template<typename... Args>
struct make_void
{
    using type = void;
};

template<typename... Args>
using void_t = typename make_void<Args...>::type;


template<bool First_value, typename First, typename... Rest>
struct __disjunction : type_identity<First> { };

template<typename False, typename Next, typename... Rest>
struct __disjunction<false, False, Next, Rest...> : __disjunction<Next::value, Next, Rest...>::type { };

template<typename... Traits>
struct disjunction : std::false_type { };

template<typename First, typename... Rest>
struct disjunction<First, Rest...> : __disjunction<First::value, First, Rest...>::type { };


template<bool First_value, typename First, typename... Rest>
struct __conjunction : type_identity<First> { };

template<typename True, typename Next, typename... Rest>
struct __conjunction<true, True, Next, Rest...> : __conjunction<Next::value, Next, Rest...>::type { };

template<typename... Traits>
struct conjunction : std::true_type { };

template<typename First, typename... Rest>
struct conjunction<First, Rest...> : __conjunction<First::value, First, Rest...>::type { };


template<typename T>
using remove_cvref_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;


template<typename T, T... Ints>
struct integer_sequence
{
    using value_type = T;
    using type = integer_sequence;
    static constexpr std::size_t size() noexcept
    {
        return sizeof...(Ints);
    }
};


template<std::size_t... Ints>
using indedx_sequence = integer_sequence<std::size_t, Ints...>;



template<typename T>
using __invoke = typename T::type;

template<std::size_t... Ints>
using __int_seq = indedx_sequence<Ints...>;


template<std::size_t N, typename S1, typename S2>
struct __concat_impl;

template<std::size_t N, std::size_t... I1, std::size_t... I2>
struct __concat_impl<N, __int_seq<I1...>, __int_seq<I2...>> : __int_seq<I1..., (N + I2)...> { };


template<std::size_t N, typename S1, typename S2>
using __concat = __invoke<__concat_impl<N, S1, S2>>;


template<std::size_t N>
struct __make_int_seq : __concat<N / 2, __invoke<__make_int_seq<N / 2>>, __invoke<__make_int_seq<N - N / 2>>> { };

template<>
struct __make_int_seq<0> : __int_seq<> { };

template<>
struct __make_int_seq<1> : __int_seq<0> { };



template<typename T, T N>
using make_integer_sequence = __invoke<__make_int_seq<N>>;


template<std::size_t N>
using make_index_sequence = __invoke<__make_int_seq<N>>;



}   // namespace detail




// function template
namespace detail
{

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


}   // namespace detail




// basic_string_view
namespace detail
{

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
    basic_string_view(const std::basic_string<CharT, Traits, Alloc>& str) noexcept
        : data_(str.data()), size_(str.size()) { }

#ifdef __HAS_CXX17
    basic_string_view(std::basic_string_view<CharT> str) noexcept
        : data_(str.data()), size_(str.size()) { }
#endif // __HAS_CXX17



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




// type alias/template meta function
namespace detail
{

using size_type         = std::size_t;
using string_type       = std::string;
using string_view       = basic_string_view<char>;


using arg_value_type    = std::function<void(std::ostream&)>;
using arg_type          = std::pair<string_view, arg_value_type>;


template<typename T>
struct is_arg_type : std::is_same<arg_type, remove_cvref_t<T>> { };

template<typename T, typename = void>
struct to_arg_type : std::false_type { };

template<typename T>
struct to_arg_type<T, void_t<decltype(std::declval<std::ostream&>() << std::declval<const T&>())>> : std::true_type { };

template<typename T>
struct as_arg_type : disjunction<is_arg_type<T>, to_arg_type<T>> { };

template<typename... Args>
struct as_arg_type_list : conjunction<as_arg_type<Args>...> { };


}   // namespace detail




// exception
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




// forward declaration
template<typename... Args>
inline auto format(detail::string_view fmt, Args&&... args) 
    -> typename std::enable_if<detail::as_arg_type_list<Args...>::value, detail::string_type>::type;




// basic_format_args
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
    
    template<typename K, typename V>
    using map_type          = std::map<K, V>;


public:
    basic_format_args() = default;
    
    basic_format_args(const basic_format_args&) = delete;
    
    basic_format_args& operator=(const basic_format_args&) = delete;

    template<typename... Args>
    basic_format_args(Args&&... args)
        : basic_format_args(detail::make_index_sequence<sizeof...(args)>{},
                            std::forward_as_tuple(std::forward<Args>(args)...)) { }
    
    template<std::size_t... Idxs, typename... Args>
    basic_format_args(indedx_sequence<Idxs...>, std::tuple<Args...>&& tup)
    {
        make_args({ __arg<Idxs>(std::get<Idxs>(tup), is_arg_type<Args>{})... });
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
    static arg_value_type arg_value(const T& val) noexcept
    {
        return [&val](std::ostream& os) { os << val; };
    }


    template<typename T>
    static auto num_arg(size_type num, T&& val) noexcept
        -> typename std::enable_if<to_arg_type<T>::value, arg_type>::type
    {
        return { num_arg_id(num), arg_value(std::forward<T>(val)) };
    }


    template<typename T>
    static auto name_arg(string_view name, T&& val) noexcept
        -> typename std::enable_if<to_arg_type<T>::value, arg_type>::type
    {
        return { name, arg_value(std::forward<T>(val)) };
    }


private:
    template<std::size_t Idx, typename T>
    arg_type __arg(T&& val, std::false_type)
    {
        return num_arg(Idx, std::forward<T>(val));
    }

    template<std::size_t Idx, typename T>
    arg_type __arg(T&& val, std::true_type)
    {
        return std::move(val);
    }

    void make_args(init_list_type<arg_type> args_list)
    {
        size_type id = 0;
        for (auto&& name_val : args_list)
        {
            auto arg_id = num_arg_id(id++);
            if (name_val.first != arg_id)
            {
                args_.emplace(arg_id, name_val.second);         // num  arg
            }
            args_.emplace(std::move(name_val));                 // name arg
        }
    }

    
private:
    map_type<string_view, arg_value_type>   args_;
    
};


using format_args    = basic_format_args<char>;


#define __NAME_ARG(x)               sfmt::detail::format_args::name_arg(STR(x), x)


}   // namespace detail




// basic_format_parse
namespace detail
{

template<typename CharT>
class basic_format_parse
{
public:
    using value_type = CharT;
    using format_t = unsigned int;
	
    enum class arg_format : format_t
    {
        fmt_escape = 0,     // {{}}


        fmt_fill_left,      // <
        fmt_fill_right,     // >


        fmt_symb_add,       // +
        fmt_symb_sub,       // -


        fmt_width,          // width
        fmt_prec,           // precision
        fmt_bool,           // bool


        fmt_type_o,         // 0o5
        fmt_type_d,         // 29
        fmt_type_x,         // 0x
        fmt_type_X,         // 0X
        fmt_type_e,         // 0.7e2
        fmt_type_E,         // 0.7E2
        fmt_type_f,         // 3.14
        fmt_type_p,         // 0x12345678
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
    string_view::value_type curr_char() const
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
            throw parse_error("parse format begin error, not found '{'");
        }

        parse_arg();

        if (next_char() != '}')
        {
            throw parse_error("parse format end error, not found '}'");
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

        // parse o/d/x/X/e/E/f/F/p
        parse_type();

    }


    void parse_fill()
    {
        bool has_align = false;
        auto curr = curr_char();
        auto align_fmt = curr;
        if (curr == '<' || curr == '>')
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



}   // namespace detail




// basic_formatter
namespace detail
{

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


    bool has_arg_fmt(format_t fmts, arg_format arg_fmt) const noexcept
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



        if (has_arg_fmt(fmts, arg_format::fmt_width))
        {
            os << std::setfill(fmt_parse.get_fill_char()) << std::setw(fmt_parse.get_width());
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
            os << std::showbase << std::scientific << std::nouppercase;
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
            os << std::showbase << std::hex << std::nouppercase;
        }


        arg.second(os);
        os.unsetf(os.flags());


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



}   // namespace detail




// vformat
namespace detail
{

inline static string_type vformat(string_view fmt, const format_args& args)
{
    return formatter(fmt, args).to_string();
}

inline static void vformat(std::ostream& os, string_view fmt, const format_args& args)
{
    formatter(fmt, args).to_ostream(os);
}


}   // namespace detail



////////////////////////////////////////////////////////////////////////////////

// public interface

#define NAME_ARG(name, x)           sfmt::detail::format_args::name_arg(name, x)
#define NAME_ARGS(...)              UNPACK(__NAME_ARG, __VA_ARGS__)



template<typename... Args>
inline auto format(detail::string_view fmt, Args&&... args) 
    -> typename std::enable_if<detail::as_arg_type_list<Args...>::value, detail::string_type>::type
{
    return detail::vformat(fmt, detail::format_args(std::forward<Args>(args)...));
}


template<typename... Args>
inline auto print(std::ostream& os, detail::string_view fmt, Args&&... args) 
    -> typename std::enable_if<detail::as_arg_type_list<Args...>::value>::type
{
    detail::vformat(os, fmt, detail::format_args(std::forward<Args>(args)...));
}


template<typename... Args>
inline auto print(detail::string_view fmt, Args&&... args) 
    -> typename std::enable_if<detail::as_arg_type_list<Args...>::value>::type
{
    detail::vformat(std::cout, fmt, detail::format_args(std::forward<Args>(args)...));
}


}   // namespace sfmt

#endif // FORMAT_HPP