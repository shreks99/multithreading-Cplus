#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <chrono>

using namespace std::literals;
std::mutex print_mutex;

void task(std::string str) {
    for(int i=0;i<5;i++){
        try {
            std::lock_guard<std::mutex> lck_guard(print_mutex);
            std::cout << str[0] << str[1] << str[2] << std::endl;
         //   throw std::exception();
            std::this_thread::sleep_for(50ms);
        } catch (std::exception& e){
            std::cout << "Excpetion caught" << e.what() << '\n';
        }
    }
}
void task_unique_lock(std::string str) {
    for(int i=0;i<5;i++){
        try {
            std::unique_lock<std::mutex> unique_lck(print_mutex);
            std::cout << str[0] << str[1] << str[2] << std::endl;
         //   throw std::exception();
         /*
         we can call after critical section 
         avoids blocking other threads while we excute non-critical section
         */
            unique_lck.unlock();
            std::this_thread::sleep_for(50ms);
        } catch (std::exception& e){
            std::cout << "Excpetion caught" << e.what() << '\n';
        }
    }
}
int main() {
    // std::thread thr1(task,"abc");
    // std::thread thr2(task,"def");
    // std::thread thr3(task,"xyz");
    
    std::thread thr1(task_unique_lock,"abc");
    std::thread thr2(task_unique_lock,"def");
    std::thread thr3(task_unique_lock,"xyz");
      
    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}