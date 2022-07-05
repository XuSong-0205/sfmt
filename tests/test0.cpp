#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream>
#include <chrono>
#include "../include/format.hpp"
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
    static const std::string path = R"(F:\code\cpp\test\test2\data\)";
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
        sfmt::print(ofile, "{}: {}\t 测试QAQ~，第 {} 条\n", __FILE__, __LINE__, i);
    }
    auto t1 = get_now();
    auto str = sfmt::format("{} 条格式化输出，共花费 {} ms\n", COUNT, (t1 - t0).count());
    sfmt::print(ofile, str);
    sfmt::print(str);

}


struct Point
{
    int x_;
    int y_;
    Point(int x = 0, int y = 0) : x_(x), y_(y) 
    { 
        sfmt::print("struct Point 构造函数调用\n");
    }
    Point(const Point& other)
    {
        copy(other);
        sfmt::print("struct Point 拷贝构造函数调用\n");
    }
    Point(Point&& other)
    {
        copy(other);
        sfmt::print("struct Point 移动构造函数调用\n");
    }
    Point& operator=(const Point& other)
    {
        if (this != &other)
        {
            copy(other);
        }

        sfmt::print("struct Point 拷贝赋值运算符调用\n");
        return *this;
    }
    Point& operator=(Point&& other)
    {
        if (this != &other)
        {
            copy(other);
        }

        sfmt::print("struct Point 移动赋值运算符调用\n");
        return *this;
    }
    ~Point()
    {
        sfmt::print("struct Point 析构函数调用\n");
    }


    void copy(const Point& other)
    {
        x_ = other.x_;
        y_ = other.y_;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        return os << sfmt::format("[{}, {}]", p.x_, p.y_);
    }
};


void test1()
{
    // 默认参数 {}              √
    // 位置参数 {0}, {1}        √
    // 名字参数 {name}, {age}   √

    int age = 18;
    int count = 2;
    std::cout << sfmt::format("第一个: { 1 }, 还是第一个: {1}, 第零个: {}, 第一个: {} QAQ~\n", 123, 666);
    std::cout << sfmt::format("count: {count}, age: {age}, [{age}, {count}] end... QWQ~\n", NAME_ARGS(age, count));

    // 自定义类型测试， no copy
    Point start(1, 2);
    sfmt::print("自定义类型 Point 测试, start: {start}\n", NAME_ARGS(start));
    sfmt::print(std::clog, "std::clog 测试, start: {start}\n", NAME_ARGS(start));

    // std::ostringstream 测试
    std::stringstream ss;
    sfmt::print(ss, "std::stringstream print() 测试\n");
    sfmt::print("ss 输出测试: {}\n", ss.str());

    // std::ofstream 测试
    const auto file_path = get_path() + "ofile.txt";
    std::ofstream ofile(file_path);
    sfmt::print(ofile, "std::ofstream 文件测试, 路径: {file_path}\n", NAME_ARGS(file_path));

    sfmt::print("test1 end...\n");
}


void test2()
{
    // 问题/BUG:
    // x. 格式化串不能只包含单个 '{' 字符

    // 下一步优化：
    // x. 将输出的流实现优化为其他实现？（待定）

    // 增加功能：
    // x. 增加对 unicode 字符的支持?(wchar_t)


    const auto func_name = "test2";
    const sfmt::detail::string_view sview0(func_name);
    constexpr auto str = "basic_string_view";
    constexpr sfmt::detail::basic_string_view<char> str_view(str, 18);
    constexpr auto beg = str_view.begin();
    constexpr auto end = str_view.end();
    constexpr auto tmp = str_view.substr(6, 12);
    constexpr auto t_beg = tmp.begin();

    sfmt::print("str: {str}, tmp: {tmp}\n", NAME_ARGS(str, tmp));
    sfmt::print("嵌套测试 str: {{ str }}\n", NAME_ARGS(str));
    sfmt::print("格式化输出测试: \n");
    sfmt::print("left: {:s<6}, right: {:x>6}\n", 0, 1, 2);

    double pi = 3.14159265358;
    double rad2 = 1.4142135;
    sfmt::print("pi: {pi:10.7}, sqrt(2): { 1:10.6 }\n", NAME_ARGS(pi, rad2));
    sfmt::print("pi: {:10.7e}, sqrt(2): {1:10.7E}\n", pi, rad2);


    char c = 120;
    int num = 612;
    sfmt::print("{:6}\n", 42);                    // 打印 "    42"
    sfmt::print("{:6}\n", 'x');                   // 打印 "     x"
    sfmt::print("{:*<6}\n", 'x');                 // 打印 "x*****"
    sfmt::print("{:*>6}\n", 'x');                 // 打印 "*****x"
    sfmt::print("{:6d}\n", c);                    // 打印 "   120"
    sfmt::print("{:6b}\n", true);                 // 打印 "  true"
    sfmt::print("{:6o}\n", num);                  // 打印 " 01144"
    sfmt::print("{0:6d}\n", num);                 // 打印 "   612"
    sfmt::print("{num:6x}\n", NAME_ARGS(num));    // 打印 " 0x264"
    sfmt::print("{ num:6X }\n", NAME_ARGS(num));  // 打印 " 0X264"
    sfmt::print("{:p}\n", &num);                  // 打印 "0x******"
    
    std::string fmt = "起名测试: {test:@<20}, 名字参数: {num}, 默认位置参数: {}, 位置参数: {1}\n";
    // 错误，NAME_ARGS() 宏中不能是字符串字面量
    // sfmt::print(fmt, NAME_ARGS(num, "临时变量"), NAME_ARG("test", "测试成功！"));

    // C++17 string_view 测试
    using namespace std::string_view_literals;
    sfmt::print("{} test...\n"sv, "std string_view");

    // sfmt::print("{ 右括号不闭合测试~\n", 233);
    // sfmt::print("{{ 嵌套测试~\n", 233);
    // sfmt::print("max id test: {64}\n", 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
    //         64);
    // sfmt::print("not name test: {unknown}\n", NAME_ARG("test", "something"));


    {
        sfmt::print("{0} {1} {2}\n", 0, NAME_ARG("1", 1), 2);
        auto a = 0;
        auto b = 3.14;
        auto c = "sfmt";
        sfmt::print("{} {} {}, {0} {1} {2}, {a} {b} {2}\n", NAME_ARGS(a, b), c);

        auto n0 = "xixi";
        auto v0 = "me";
        sfmt::print(sfmt::format("name: {{}}, love: {{}}!\n", "n0", "v0"), NAME_ARGS(n0, v0));

    }

}



void add_func()
{
    get_funcs().emplace_back(test0);
    get_funcs().emplace_back(test1);
    get_funcs().emplace_back(test2);
}


int main()
{
    add_func();
    get_funcs().back()();
    // for (auto&& func : get_funcs())
    // {
    //     func();
    // }

    std::cout << "main end...\n";
    return 0;
}