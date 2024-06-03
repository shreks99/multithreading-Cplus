#include <iostream>
#include <thread>

class Singleton{
private:
    Singleton() = default;
public:
    static Singleton& get_instance() {
        static Singleton single;
        return single;
    }

};

void task() {
    Singleton& s1 = Singleton::get_instance();
    std::cout<< &s1 << std::endl;
}

int main() {
    
    std::thread t1(task);
    std::thread t2(task);

    t1.join();
    t2.join();
    return 0;
}