#include "classic_singleton.h"
#include <vector>
#include <thread>

// Singleton* Singleton::single = nullptr;
void task() {
    Singleton& single = get_Singleton();
    std::cout<< &single <<std::endl;
}
int main() {
    std::vector<std::thread> tasks;
    for(int i=0;i< 10;i++)
        tasks.push_back(std::thread(task));
    
    for(auto& t:tasks) t.join();
    return 0;
}