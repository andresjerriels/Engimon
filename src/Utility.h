#ifndef UTIL_H
#define UTIL_H
#include<string>
#include<iostream>

class Util
{
public:
    static void printFormatKiri(std::string str){
        std::cout << "* " << str << std::string((49-str.length()), ' ') << " *\n";
    }

    static void printFormatKanan(std::string str){
        std::cout << "* " << std::string((49-str.length()), ' ') << str << " *\n";
    }
};
#endif