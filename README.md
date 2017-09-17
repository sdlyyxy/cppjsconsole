# cppjsconsole

## 概况

A partial implementation of JavaScript 'console' in C++. 

JavaScript 的 console 在 C++ 中的一部分实现。安装后可以直接`#include<cppjsconsole.h>`使用。

[JavaScript console 的 API](https://developer.mozilla.org/zh-CN/docs/Web/API/Console)。

由于我原来不知道模板把声明和实现分离很麻烦，于是用了cmake，显然目前没什么用了。

## 安装

```
mkdir build
cd build
cmake ..
make install
```