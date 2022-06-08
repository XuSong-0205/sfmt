#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <tuple>
#include "test_format.hpp"
#include "format.hpp"



std::vector<std::function<void()>>& get_funcs()
{
    static std::vector<std::function<void()>> funcs;
    return funcs;
}


void test0()
{
    constexpr int COUNT = 10;
    for (int i = 0; i < COUNT; ++i)
    {
        mini::print("[{}, {}]\n", i, i + 3.14);
        LOG_INFO(i, 3.14, "test", "QAQ", MAKE_STR(i, COUNT, QwQ));
    }
}


struct Point
{
    int x_;
    int y_;
    Point(int x = 0, int y = 0) : x_(x), y_(y) { }
    
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

    Point start(1, 2);
    std::cout << sx::format("自定义类型 Point 测试, start: {start}\n", NAME_ARGS(start));
}


void add_func()
{
    get_funcs().emplace_back(test0);
    get_funcs().emplace_back(test1);
}


int main()
{
    add_func();
    get_funcs().back()();

    std::cout << "main end...\n";
    return 0;
}