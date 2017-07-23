#include <iostream>
#include <stdio.h>

void printFe(const char * message){
    std::cout<<message;
}

template<typename T, typename... Args>
void printFe(const char *message, T val, Args ... args) {
    while (*message) {
        if (*message != '%') {
            std::cout<<*message;
            message++;
        } else {
            std::cout<<val;
            printFe(message + 1, args...);
            break;
        }
    }
}
