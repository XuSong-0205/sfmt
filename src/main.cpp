#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include "format.hpp"
using namespace std::chrono;


std::vector<std::function<void()>>& get_funcs()
{
    static std::vector<std::function<void()>> funcs;
    return funcs;
}


const auto get_now = []()
{
    return time_point_cast<milliseconds>(steady_clock::now());
};


const  std::string& get_path()
{
    static const std::string path = R"(E:\VScode\code\cpp_code\Test\test_format\data\)";
    return path;
}



void test0()
{
    // 性能测试
    constexpr int COUNT = 1000 * 100;
    const auto path = get_path() + "test0.txt";
    std::ofstream ofile(path);

    auto t0 = get_now();
    for (int i = 0; i < COUNT; ++i)
    {
        sx::print(ofile, "{}: {}\t 测试QAQ~，第 {} 条\n", __FILE__, __LINE__, i);
    }
    auto t1 = get_now();
    auto str = sx::format("{} 条格式化输出，共花费 {} ms\n", COUNT, (t1 - t0).count());
    sx::print(ofile, str);
    sx::print(str);

}


struct Point
{
    int x_;
    int y_;
    Point(int x = 0, int y = 0) : x_(x), y_(y) 
    { 
        sx::print("struct Point 构造函数调用\n");
    }
    Point(const Point& other)
    {
        copy(other);
        sx::print("struct Point 拷贝构造函数调用\n");
    }
    Point(Point&& other)
    {
        copy(other);
        sx::print("struct Point 移动构造函数调用\n");
    }
    Point& operator=(const Point& other)
    {
        if (this != &other)
        {
            copy(other);
        }

        sx::print("struct Point 拷贝赋值运算符调用\n");
        return *this;
    }
    Point& operator=(Point&& other)
    {
        if (this != &other)
        {
            copy(other);
        }

        sx::print("struct Point 移动赋值运算符调用\n");
        return *this;
    }
    ~Point()
    {
        sx::print("struct Point 析构函数调用\n");
    }


    void copy(const Point& other)
    {
        x_ = other.x_;
        y_ = other.y_;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        return os << sx::format("[{}, {}]", p.x_, p.y_);
    }
};


void test1()
{
    // 默认参数 {}              √
    // 位置参数 {0}, {1}        √
    // 名字参数 {name}, {age}   √

    int age = 18;
    int count = 2;
    std::cout << sx::format("第一个: { 1 }, 还是第一个: {1}, 第零个: {}, 第一个: {} QAQ~\n", 123, 666);
    std::cout << sx::format("count: {count}, age: {age}, [{age}, {count}] end... QWQ~\n", NAME_ARGS(age, count));

    // 自定义类型测试， no copy
    Point start(1, 2);
    sx::print("自定义类型 Point 测试, start: {start}\n", NAME_ARGS(start));
    sx::print(std::clog, "std::clog 测试, start: {start}\n", NAME_ARGS(start));

    // std::ostringstream 测试
    std::stringstream ss;
    sx::print(ss, "std::stringstream print() 测试\n");
    sx::print("ss 输出测试: {}\n", ss.str());

    // std::ofstream 测试
    const auto file_path = get_path() + "ofile.txt";
    std::ofstream ofile(file_path);
    sx::print(ofile, "std::ofstream 文件测试, 路径: {file_path}\n", NAME_ARGS(file_path));

    sx::print("test1 end...\n");
}


void test2()
{
    // 下一步优化：
    // 1. to_string 优化
    // 2. string 优化为 string_view
    // 3. 将输出的流实现优化为其他实现？（待定）


    // 增加功能：
    // 1. 增加浮点数的可选格式化输出 {name:x.y}
    // 2. 增加可选的格式化对齐? {name:<10}
    // 3. 增加对 unicode 字符的支持?(wchar_t)


    std::map<std::string, int> my_map;
    std::string s0;
    std::string s1;
    auto x = s0 < s1;



    constexpr auto str = "basic_string_view";
    constexpr sx::detail::basic_string_view<char> str_view(str, 18);
    constexpr auto beg = str_view.begin();
    constexpr auto end = str_view.end();
    constexpr auto tmp = str_view.substr(6, 12);
    constexpr auto t_beg = tmp.begin();

    sx::print("str: {str}, tmp: {tmp}\n", NAME_ARGS(str, tmp));

}



void add_func()
{
    // get_funcs().emplace_back(test0);
    // get_funcs().emplace_back(test1);
    get_funcs().emplace_back(test2);
}


int main()
{
    add_func();
    get_funcs().back()();

    std::cout << "main end...\n";
    return 0;
}