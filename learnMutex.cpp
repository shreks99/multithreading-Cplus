#include<iostream>
#include<mutex>
#include<thread>
#include<vector>

std::mutex task_mutex;
using namespace std::literals;

void task(const std::string& str) {
    for(int i=0;i<5;i++) {
       task_mutex.lock();
        std::cout<<str[0] << str[1] << str[2] << std::endl;
       task_mutex.unlock();
    }
}
void task1() {
    std::cout<< "Task1 trying to lock the mutex"<< std::endl;
    task_mutex.lock();
    std::cout <<"Task 1 locked the mutex" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::cout<< "Task1 is unlocking the mutex"<<std::endl;
    task_mutex.unlock();
}
void task2() {
    std::this_thread::sleep_for(100ms);
    std::cout<< "Task2 trying to lock the mutex"<< std::endl;
    while(!task_mutex.try_lock()) {
        std::cout<< "Task2 could not lock the mutex"<< std::endl;
        std::this_thread::sleep_for(100ms);

    }
    std::cout <<"Task 2 locked the mutex" << std::endl;
    task_mutex.unlock();
}
int main() {
    // std::thread thr1(task,"abc");
    // std::thread thr2(task,"def");
    // std::thread thr3(task,"xyz");
    std::thread thr1(task1);
    std::thread thr2(task2);
    thr1.join();
    thr2.join();
    //thr3.join();
    return 0;

}