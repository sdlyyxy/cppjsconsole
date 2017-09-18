#include "cppjsconsole.h"
#include <cstdio>
#include <cstdlib>

Console console;
void Console::log()
{
    puts("");
    newline = true;
}
void Console::clear()
{
    system("clear");
}
void Console::debug()
{
    this->log();
}
void Console::error()
{
    this->log("console.error: ");
}
void Console::exception()
{
    this->error();
}
void Console::groupEnd()
{
    numOfGroups--;
    if (numOfGroups < 0)
        numOfGroups = 0;
}
void Console::info()
{
    this->log("console.info: ");
}
void Console::warn()
{
    this->log("console.warn: ");
}
void Console::group()
{
    numOfGroups++;
}