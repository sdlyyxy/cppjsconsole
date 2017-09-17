#ifndef CPPJSCONSOLE_H
#define CPPJSCONSOLE_H

#include <map>
#include <string>
class Console
{
  private:
    std::map<std::string, void *> typeToMap;

  public:
    template <typename T>
    void time(T foo);
    template <typename T>
    void timeEnd(T foo);
    template <typename T>
    void log(T foo);
    void clear();
    template <typename T>
    void assert(bool flag, T foo);
};
// extern Console console;

#include "globals.h"
#include "cppjsconsole.cpp"

#endif /* CPPJSCONSOLE_H */