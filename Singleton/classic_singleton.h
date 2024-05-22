#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

class Singleton {
    //Don't include here
    // static Singleton* single;

   
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator=(const Singleton&&) = delete;

     Singleton() {
        std::cout << "Intialing Singleton" << std::endl;
    }
    // static Singleton* get_Singleton();
};
Singleton& get_Singleton();

#endif
