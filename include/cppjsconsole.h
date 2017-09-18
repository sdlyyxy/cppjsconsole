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

class Console{
    private:
        std::map<std::string,void*> typeToMap;
        int numOfGroups=0;
        bool newline=true;
        std::string groupTab="    ";
    public:
        template <typename T>
        void time(T foo){
            static std::map<T,int> paraToTime;
            typeToMap[typeid(T).name()]=(void*)&paraToTime;
            paraToTime[foo]=clock();
        }
        template <typename HEAD,typename... TYPES>
        void log(HEAD head,TYPES... tail){
            if(newline)for(int i=0;i<numOfGroups;i++)
                std::cout<<groupTab;
            newline=false;
            std::cout<<head<<' ';
            this->log(tail...);
        }
        void log(){
            puts("");
            newline=true;
        }
        template <typename T>
        void timeEnd(T foo){
            // std::string hehe;
            std::map<T,int> paraToTime=*((std::map<T,int>*)typeToMap[typeid(T).name()]);
            int preTime=paraToTime[foo];
            // std::cout<<foo;
            int output=(clock()-preTime+.0)/CLOCKS_PER_SEC*1000;
            // printf(": %dms\n",output);
            std::stringstream ss;
            ss<<foo<<": "<<output<<"ms";
            std::string res;
            char c;
            while(ss>>c)res+=c;
            this->log(res);
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
                this->log("Assertion failed: ",foo);
                // std::cout<<foo<<std::endl;
            }
        }
        template <typename... T>
        void debug(T... foo){
            this->log(foo...);
        }
        void debug(){
            this->log();
        }
        template <typename... T>
        void error(T... foo){
            // printf("console.error: ");
            this->log("console.error: ",foo...);
        }
        void error(){
            // printf("console.error: \n");
            this->log("console.error: ");
        }
        template <typename... T>
        void exception(T... foo){
            this->error(foo...);
        }
        void exception(){
            this->error();
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
        template <typename... T>
        void info(T... foo){
            // printf("console.info: ");
            this->log("console.info: ",foo...);
        }
        void info(){
            // printf("console.info: \n");
            this->log("console.info: ");
        }
        template <typename... T>
        void warn(T... foo){
            // printf("console.warn: ");
            this->log("console.warn: ",foo...);
        }
        void warn(){
            // printf("console.warn: \n");
            this->log("console.warn: ");
        }
        void trace(){

        }
};
Console console;
#endif /* CPPJSCONSOLE_H */