#include<thread>
#include<iostream>

class FunctorHello {
public:
    void operator()() {
        std::cout << "\nhello, functor";
    }
    void operator()(int a, int b) {
        std::cout << a + b;
    }
    void hello() {
        std::cout << "\nhello inside class FunctorHello id:: "<<std::this_thread::get_id() << std::endl;
    }
};
//callable object thread entry point
void hello() {
    std::cout<< "\nHello World";
}

void func(std::string&& str) {
    std::cout << "\nOwernship of " << str << " transferred to thread";
}
// Reference wrapper use
void funcRef(std::string& str) {
    str = "xyz";
}
int main() {
    //create thread object and pass the task function to constructor
    std::thread thr(hello);
    //wait for thread to complete and not call thread terminate 
    thr.join();

    FunctorHello functorHello;
    std::thread thr1(functorHello);
    std::cout<< "\nID after functorHello id::" << thr1.get_id();
    std::thread thr2(functorHello,2,3);
    std::string str = "moveable";
    std::thread thr3(func, std::move(str));
    std::thread thr4(funcRef,std::ref(str));
    std::cout<< "\n str is now" << str << std::endl;

    std::thread thr5(&FunctorHello::hello,&functorHello);
    std::thread thr6([str](int i1, int i2){ 
        std::cout << "\nInside lambda "<< str << i1 + i2 << '\n';
        },200,3);
    thr3.join();
    thr1.join();
    thr2.join();
    thr4.join();
    thr5.join();
    thr6.join();
    std::cout<< "\nID after functorHello join id::" << thr1.get_id();

    std::cout<< "\n" << str.size();
}