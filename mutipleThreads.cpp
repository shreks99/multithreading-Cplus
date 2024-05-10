#include<iostream>
#include<thread>
#include<vector>

int z = 0;
void hello(int num) {
    using namespace::std::literals;
    std::this_thread::sleep_for(2s);
    std::cout<< "\nHello from thread" << num <<'\n';
}

//Data Race
void print(std::string str) {
    for(int i = 0;i<5;i++) {
        std::cout<< str[0] << str[1] << str[2] << std::endl;
    }
}
 auto incr = [](){
       for(int i =0;i<100000;i++)z++;
    };
int main() {
    std::cout<< "Starting thread";
    // std::thread thr1(hello,1);
    // std::thread thr2(hello,2);
    // std::thread thr3(hello,3);
    // thr1.join();
    // thr2.join();
    // thr3.join();

    std::vector<std::thread> tasks;
    for(int i=0;i<3;i++) tasks.push_back(std::thread{incr});
    for(auto & t:tasks) t.join();
    std::cout<<z<<std::endl;
    return 0;
}