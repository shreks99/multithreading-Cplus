#include<iostream>
#include<random>

//use thread_local std::mt19937 mt;
/*
Each thread will have its own mt19937 random number generator, initialized independently.
This can improve performance in multithreaded applications where random number generation occurs frequently.
Each thread will generate its own sequence of random numbers independently from other threads.
*/
std::mt19937 mt;

int main() {
    std::uniform_int_distribution<int> uid(0,100);
    for(int i=0;i<10;i++) std::cout<<uid(mt)<<", ";

    std::uniform_real_distribution<double> did(0,1);
    for(int i=0;i<10;i++) std::cout<<did(mt)<<", ";
    return 0;
}