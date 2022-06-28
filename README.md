# sfmt 

## sfmt 是一个基于 C++11 的简单格式化工具库

> 特点：
> C++11、简单易用、单头文件、效率一般

-----------------------


## 下载

```bash
git clone xxx
```


## 使用

```cpp
#include "sfmt/include/smft.hpp"
```


## 用法

1. 使用`默认位置参数`
```cpp
void test1()
{
    // 在这里 "{}" 表示占位符，后续的 "hello" 和 "sfmt" 是参数
    // 参数会依次替换掉格式化字符串中的 "{}"
    sfmt::print("{} {}!\n", "hello", "sfmt");
    // hello sfmt!

    // 如果参数个数小于占位符 "{}" 的个数，则会抛出异常
    // sfmt::print("{} {}!\n", "hello");            // 错误，参数个数不足，抛出异常

    // 如果参数个数大于占位符 "{}" 的个数，则多余的参数会被忽略
    sfmt::print("{} {}\n", "hello", "sfmt", "!");  // 最后的 "!" 被忽略
    // hello sfmt
}

```


2. 使用`位置参数`
```cpp
void test2()
{
    // 使用位置参数时，可以在 "{}" 指定参数的位置，参数位置从 0 开始
    // 注意：位置参数必须为无前导 0 的非负十进制整数，否则会抛出异常
    sfmt::print("{1} {0}!\n", "world", "sfmt");
    // hello sfmt!

    // 注意，若位置参数超过了实际参数个数，则会在运行时抛出异常
    // sfmt::print("{0} {2}!\n", "hello", "sfmt");          // 错误，抛出异常

    // 若参数个数过多，则会忽略多余的参数
    sfmt::print("{0} {1}!\n", "hello", "sfmt", "world");    // 正确，忽略 "world"
    // hello sfmt!
}
```


3. 使用`命名参数`
```cpp
void test3()
{
    // 使用命名参数时，可以在 "{}" 指定参数的名称
    // 对于左值变量需要写在 NAME_ARGS() 宏中，这样才能获取到变量的名称
    auto h = "hello";
    auto s = "sfmt";
    sfmt::print("{h} {s}!\n", NAME_ARGS(s, h));
    // hello sfmt!

    // 

}

```



## 注意事项

> 1. 格式化字符串中不能包含单独的 '{' 字符，否则会抛出异常，但可以包含单独的 '}' 字符
> 2. xxx