#ifndef CPPJSCONSOLE_H
#define CPPJSCONSOLE_H

#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

class Console{
    private:
        std::map<std::string,void*> typeToMap;
    public:
        template <typename T>
        void time(T foo){
            std::map<T,int> paraToTime;
            typeToMap[typeid(T).name()]=(void*)&paraToTime;
            paraToTime[foo]=clock();
        }
        template <typename T>
        void timeEnd(T foo){
            std::map<T,int> paraToTime=*((std::map<T,int>*)typeToMap[typeid(T).name()]);
            int preTime=paraToTime[foo];
            std::cout<<foo;
            int output=(clock()-preTime+.0)/CLOCKS_PER_SEC*1000;
            printf(": %dms\n",output);
        }
        template <typename T>
        void log(T foo){
            std::cout<<foo<<std::endl;
        }
        void clear(){
            system("clear");
        }
        template <typename T>
        static void assert(bool flag,T foo){
            try{
                if(!flag)throw foo;
            }
            catch(T){
                printf("Assertion failed: ");
                std::cout<<foo<<std::endl;
            }
        }
};
Console console;
#endif /* CPPJSCONSOLE_H */