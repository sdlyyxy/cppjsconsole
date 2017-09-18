# cppjsconsole 

[![Build Status](https://travis-ci.org/sdlyyxy/cppjsconsole.svg?branch=master)](https://travis-ci.org/sdlyyxy/cppjsconsole) [![codecov](https://codecov.io/gh/sdlyyxy/cppjsconsole/branch/master/graph/badge.svg)](https://codecov.io/gh/sdlyyxy/cppjsconsole)

## 概况

A partial implementation of JavaScript 'console' in C++. 

JavaScript 的 console 在 C++ 中的一部分实现。安装后可以直接`#include<cppjsconsole.h>`使用。



## 已经实现的功能以及用法

[JavaScript console 在 FireFox 上的官方 API](https://developer.mozilla.org/zh-CN/docs/Web/API/Console)。

### `console.clear()`
清空终端，类似于bash中直接执行`clear`

### `console.time()`
计时器，接受一个参数作为标识。

### `console.timeEnd()`
接受一个参数作为标识，结束特定的计时器。输出用时多少毫秒。

### `console.log()`
打印字符串,可以接受多个，不限类型的参数，只要该类型可以cout就行。目前还不能支持类似printf的格式化输出。

### `console.assert()`
判断第一个参数是否为真，false的话抛出异常（第二个参数）并且在控制台输出相应第二个参数。

### `console.debug()`
与`console.log()`功能相同

### `console.error()`
与`console.log()`功能相似，只是多输出一个"`console.error: `"

### `console.exception()`
与`console.error()`功能相同

### `console.info()`
与`console.log()`功能相似，只是多输出一个"`console.info: `"

### `console.warn()`
与`console.log()`功能相似，只是多输出一个"`console.warn: `"

### `console.group()`
输出分组，即后面的输出增加缩进。

### `console.groupEnd()`
结束分组，减少缩进。

## 安装

```bash
mkdir build
cd build
cmake ..
make install
# 可能要 sudo make install
```

## 使用
在源文件加上`#include<cppjsconsole.h>`，编译选项加上`-lcppjsconsole`

## 实例

源文件[`test.cpp`](./src/test.cpp)

```cpp
#include "cppjsconsole.h"
#include <map>
int main()
{
	console.clear();
	console.time("loop");
	std::map<int, int> m;
	for (int i = 0; i < 80000; i++)
	{
		m[i] = i;
	}
	console.timeEnd("loop");
	console.group("Languages:");
	char *s[] = {"Chinese", "English", "Spanish", "Linyi Hua"};
	for (int i = 0; i < 4; i++)
	{
		console.log(s[i]);
	}
	console.groupEnd();
	console.assert(true, "hehe");
	console.info("Will exit,", 88, '!');

	return 0;
}
```

编译&&运行
```bash
g++ test.cpp -lcppjsconsole -o main
./main
```

输出
```
loop:15ms
Languages:
    Chinese
    English
    Spanish
    Linyi Hua
console.info:  Will exit, 88 !
```