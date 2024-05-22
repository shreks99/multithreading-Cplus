#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>

std::shared_mutex shmut;
int x = 0;

void write() {
    std::lock_guard<std::shared_mutex> lck_guard(shmut);
    x++;
}

void read() {
    std::shared_lock<std::shared_mutex> lck_guard(shmut);
    using namespace std::literals;
    std::this_thread::sleep_for(50ms);
}

int main() {
    std::vector<std::thread> tasks;
    for(int i=0;i<20;i++)
        tasks.push_back(std::thread(read));

    tasks.push_back(std::thread(write));


    for(int i=0;i<20;i++)
        tasks.push_back(std::thread(read));
    
    for(auto &t:tasks) t.join();
    return 0;
}