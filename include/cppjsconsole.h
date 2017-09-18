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
        int numOfGroups=0;
        std::string groupTab="    ";
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
        template <typename HEAD,typename... TYPES>
        void log(HEAD head,TYPES... tail){
            std::cout<<head<<' ';
            this->log(tail...);
        }
        void log(){
            puts("");
        }
        void clear(){
            system("clear");
        }
        template <typename T>
        void assert(bool flag,T foo){
            try{
                if(!flag)throw foo;
            }
            catch(T){
                printf("Assertion failed: ");
                std::cout<<foo<<std::endl;
            }
        }
        template <typename T>
        void debug(T foo){
            this->log(foo);
        }
        template <typename T>
        void error(T foo){
            printf("Console.error: ");
            this->log(foo);
        }
        template <typename T>
        void exception(T foo){
            this->error(foo);
        }
        template <typename T>
        void group(T foo){
            numOfGroups++;
            this->log(foo);
        }
        void groupEnd(){
            numOfGroups--;
            if(numOfGroups<0)numOfGroups=0;
        }
        template <typename T>
        void info(T foo){
            printf("console.info: ");
            this->log(foo);
        }
        template <typename T>
        void warn(T foo){
            printf("console.warn: ");
            this->log(foo);
        }
        void trace(){

        }
};
Console console;
#endif /* CPPJSCONSOLE_H */