// Internal Synchronization vs external synchronization
/*
    C++ STL containers needs to be externally synchronized 
        by locking a mutex before calling a member function
    Internal Synchronization
        a class which has
            an std::vector data member
            std::mutex data memeber
            member functions which lock the mutex before accessing the std::vector
            unlock the mutex after accessing it
*/
#include<thread>
#include<mutex>
#include<vector>
#include<iostream>
#include<chrono>

using namespace std::literals;

class Vector {
    std::mutex mut;
    std::vector<int> vec;

public:
    void push_back(const int& i) {
        mut.lock();
        vec.push_back(i);
        mut.unlock();

    }
    void print() {
        mut.lock();
        for(int v:vec) std::cout << v <<", ";
        std::cout<< '\n';
        mut.unlock();
    }
};
void func(Vector& vec) {
    for(int i=0;i<5;i++) {
        vec.push_back(i);
        std::this_thread::sleep_for(50ms);
        vec.print();
    }
}
int main() {
    Vector myVec;
    std::thread thr1(func,std::ref(myVec));
    std::thread thr2(func,std::ref(myVec));

    thr1.join();
    thr2.join();
    return 0;
}