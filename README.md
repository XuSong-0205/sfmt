# sfmt 

## sfmt 是一个基于 C++11 的简单格式化工具库

> 特点：
> C++11、简单易用、单头文件、效率一般

-----------------------


## 下载

```bash
git clone https://github.com/XuSong-0205/sfmt
```


## 使用

```cpp
#include "sfmt/include/format.hpp"
```


## 用法

1. 使用`默认位置参数`
```cpp
// 在这里 "{}" 表示占位符，后续的 "hello" 和 "sfmt" 是参数
// 参数会依次替换掉格式化字符串中的 "{}"
sfmt::print("{} {}!\n", "hello", "sfmt");
// hello sfmt!

// 如果参数个数小于占位符 "{}" 的个数，则会抛出异常
// sfmt::print("{} {}!\n", "hello");            // 错误，参数个数不足，抛出异常

// 如果参数个数大于占位符 "{}" 的个数，则多余的参数会被忽略
sfmt::print("{} {}\n", "hello", "sfmt", "!");  // 最后的 "!" 被忽略
// hello sfmt
```


2. 使用`位置参数`
```cpp
// 使用位置参数时，可以在 "{}" 指定参数的位置，参数位置从 0 开始
// 注意：位置参数必须为无前导 0 的非负十进制整数，否则会抛出异常
sfmt::print("{1} {0}!\n", "world", "sfmt");
// hello sfmt!

// 注意，若位置参数超过了实际参数个数，则会在运行时抛出异常
// sfmt::print("{0} {2}!\n", "hello", "sfmt");          // 错误，抛出异常

// 若参数个数过多，则会忽略多余的参数
sfmt::print("{0} {1}!\n", "hello", "sfmt", "world");    // 正确，忽略 "world"
// hello sfmt!
```


3. 使用`命名参数`
```cpp
// 使用命名参数时，可以在 "{}" 指定参数的名称
// 此时参数需要写在 NAME_ARGS() 宏中，这样才能捕获到变量的名称
auto h = "hello";
auto s = "sfmt";
sfmt::print("{h} {s}!\n", NAME_ARGS(s, h));
// hello sfmt!

// 如果是函数返回值，或者想给参数一个新的命名，可以使用 NAME_ARG() 宏完成
// NAME_ARG() 宏有两个参数，第一个是参数的名称，第二个是对应变量
auto func = [](int a, int b) { return a + b; };
auto a = 1;
auto b = 2;
sfmt::print("{a} + {b} = {c}\n", NAME_ARGS(a, b), NAME_ARG("c", func(a, b)));
// 1 + 2 = 3

// 注意，命名参数需要与 NAME_ARGS() 宏中的参数名相同，或者与 NAME_ARG() 宏中指定的名相同，否则会找不到参数，从而抛出异常
// sfmt::print("{h} {w}!\n", NAME_ARGS(h, s));      // 错误，找不到参数 "w"，抛出异常

// 多余的命名参数同样也会被忽略
sfmt::print("{h} {s}!\n", NAME_ARGS(h, s, a)));     // 正确，忽略 "a"
// hello sfmt!
```


4. 混合使用
- 混合使用`默认位置参数`和`位置参数`
`默认位置参数`和`位置参数`可以混合使用，但是要注意使用的规则
所有的`默认位置参数`按照`默认位置参数`顺序进行替换，不会与`位置参数`相互影响
例如：
```cpp
sfmt::print("{0} {2}? {} {}!\n", "hello", "sfmt", "world");
// hello world? hello sfmt!

sfmt::print("{} {2}? {0} {}!", "hello", "sfmt", "world");
// hello world? hello sfmt!
```

- 混合使用`默认位置参数`、`位置参数`和`命名参数`
同样，`默认位置参数`、`位置参数`和`命名参数`也可以混合使用，使用规则只是在上述的规则上多了一个命名规则（非常不建议多种混用，容易搞乱，就简单点用不好吗QAQ~）
例如：
```cpp
auto h = "hello";
auto s = "sfmt";
auto w = "world";
sfmt::print("{h} {}? {} {2}!", NAME_ARGS(w, h), s);
// hello world? hello sfmt!
```

## 注意事项

> 1. 格式化字符串中不能包含单独的 '{' 字符，否则会抛出异常，但可以包含单独的 '}' 字符
> 2. NAME_ARGS() 宏中不能包含字符串字面量（在 MSVC 下可能会产生编译错误）