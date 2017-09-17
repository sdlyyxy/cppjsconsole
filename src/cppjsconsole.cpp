#ifndef CPPJSCONSOLE_CPP
#define CPPJSCONSOLE_CPP

#include <iostream>
#include <cstdio>
#include <typeinfo>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "cppjsconsole.h"
template <typename T>
void Console::time(T foo)
{
    static std::map<T, int> paraToTime;
    typeToMap[typeid(T).name()] = (void *)&paraToTime;
    paraToTime[foo] = clock();
}
template <typename T>
void Console::timeEnd(T foo)
{
    std::map<T, int> paraToTime = *((std::map<T, int> *)typeToMap[typeid(T).name()]);
    int preTime = paraToTime[foo];
    std::cout << foo;
    int output = (clock() - preTime + .0) / CLOCKS_PER_SEC * 1000;
    printf(": %dms\n", output);
}
template <typename T>
void Console::log(T foo)
{
    std::cout << foo << std::endl;
}
void Console::clear()
{
    system("clear");
}
template <typename T>
void Console::assert(bool flag, T foo)
{
    try
    {
        if (!flag)
            throw foo;
    }
    catch (T)
    {
        printf("Assertion failed: ");
        std::cout << foo << std::endl;
    }
}
//Console console;

#endif /* CPPJSCONSOLE_CPP */