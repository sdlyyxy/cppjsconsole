#ifndef CPPJSCONSOLE_H
#define CPPJSCONSOLE_H

#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <sstream>

class Console
{
  private:
    std::map<std::string, void *> typeToMap;
    int numOfGroups = 0;
    bool newline = true;
    std::string groupTab = "    ";

  public:
    template <typename T>
    void time(T foo);
    template <typename HEAD, typename... TYPES>
    void log(HEAD head, TYPES... tail);
    void log();
    template <typename T>
    void timeEnd(T foo);
    void clear();
    template <typename T>
    void assert(bool flag, T foo);
    template <typename... T>
    void debug(T... foo);
    void debug();
    template <typename... T>
    void error(T... foo);
    void error();
    template <typename... T>
    void exception(T... foo);
    void exception();
    template <typename T>
    void group(T foo);
    void group();
    void groupEnd();
    template <typename... T>
    void info(T... foo);
    void info();
    template <typename... T>
    void warn(T... foo);
    void warn();
};

extern Console console;

template <typename T>
inline void Console::time(T foo)
{
    static std::map<T, int> paraToTime;
    typeToMap[typeid(T).name()] = (void *)&paraToTime;
    paraToTime[foo] = clock();
}
template <typename HEAD, typename... TYPES>
inline void Console::log(HEAD head, TYPES... tail)
{
    if (newline)
        for (int i = 0; i < numOfGroups; i++)
            std::cout << groupTab;
    newline = false;
    std::cout << head << ' ';
    this->log(tail...);
}
template <typename T>
inline void Console::timeEnd(T foo)
{
    std::map<T, int> paraToTime = *((std::map<T, int> *)typeToMap[typeid(T).name()]);
    int preTime = paraToTime[foo];
    int output = (clock() - preTime + .0) / CLOCKS_PER_SEC * 1000;
    std::stringstream ss;
    ss << foo << ": " << output << "ms";
    std::string res;
    char c;
    while (ss >> c)
        res += c;
    this->log(res);
}
template <typename T>
inline void Console::assert(bool flag, T foo)
{

    if (!flag)
    {
        this->log("Assertion failed: ", foo);
        throw foo;
    }
}
template <typename... T>
inline void Console::debug(T... foo)
{
    this->log(foo...);
}
template <typename... T>
inline void Console::error(T... foo)
{
    this->log("console.error: ", foo...);
}
template <typename... T>
inline void Console::exception(T... foo)
{
    this->error(foo...);
}
template <typename T>
inline void Console::group(T foo)
{
    this->log(foo);
    numOfGroups++;
}
template <typename... T>
inline void Console::info(T... foo)
{
    this->log("console.info: ", foo...);
}
template <typename... T>
inline void Console::warn(T... foo)
{
    this->log("console.warn: ", foo...);
}
#endif /* CPPJSCONSOLE_H */