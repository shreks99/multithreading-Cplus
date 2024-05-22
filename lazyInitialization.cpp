#include <mutex>
#include <iostream>
#include <thread>
/*
Lazy initialization (single-threaded)
Common pattern in functional programming
A variable is only intialized when it is first used
this is useful when the variable is expensive to construct(network connection)
can be used in multi-threaded code(but avoid data races)
*/

class Test {
public:
    Test() {
        std::cout<< "Test constructor\n";
    }
    void func() {}
};
Test *ptr = nullptr;

void process() {
    if(!ptr) ptr = new Test;
    ptr->func(); 
}

//make it thread-safe
/*
Use mutex unique_lock
1. std::unique_lock<std::mutex uq_lck(mut);
2. Double-checked locking
    void process() {
        if(!ptest) {
            std::lock_guard lck_guard(mut);
            if(!ptest)  //second check to avoid double intialisation
                ptest = new Test; //but still race condition because the initalization 
                involves sererval operations and performed in different order
                - allocate enough memory to store a test object
                - constrct a test object in the memory
                - store the address in ptest

        }  
    }
3. Double-checked Locking with call_once (thread-safe,less overhead than a mutex)
4. C++17 defines the order of intiazation in new i.e ptest = new Test so no longer race condition
*/

std::once_flag ptr_flag;

void ad_process() {
    std::call_once(ptr_flag, [](){
        ptr = new Test;
    });
    ptr->func();
}

int main() {
    std::thread t1(ad_process);
    std::thread t2(ad_process);
    t1.join();
    t2.join();
}