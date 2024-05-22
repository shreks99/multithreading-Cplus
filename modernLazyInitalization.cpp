// Lazy initialization (multi-threaded)
// uses Meyers singleton
#include <mutex>
#include <iostream>
#include <thread>

class Test {
public:
    Test() {
        std::cout<< "Test constructor\n";
    }
    void func() {}
};

void process() {
    static Test ptr;   //Variable is lazy initialized
    ptr.func();
}

int main() {
    std::thread t1(process);
    std::thread t2(process);
    t1.join();
    t2.join();
}
