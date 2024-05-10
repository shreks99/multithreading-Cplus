#include<iostream>
#include<thread>
void hello() {
    using namespace std::literals;

   std::cout<< "\nhello called by ::" << std::this_thread::get_id()<<",";
   std::this_thread::sleep_for(1s);
}
//thread ownership transferred to this function
void threadFunction(std::thread&& t1) {
    std::cout<< "\nthreadFunction called by ::" << t1.get_id();
        t1.join();

}

//returning the thread object will automatically move for us
std::thread retFunc() {
    std::thread thr(hello);
    return thr;
}
int main() {
    //std::thread t1(hello);
    std::thread t1 = retFunc();
    threadFunction(std::move(t1));
    std::cout << "\nthread returned to main ::" <<t1.get_id();
    return 0;
}