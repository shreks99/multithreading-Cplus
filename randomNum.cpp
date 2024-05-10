#include<iostream>
#include<random>

std::mt19937 mt;

int main() {
    std::uniform_int_distribution<int> uid(0,100);
    for(int i=0;i<10;i++) std::cout<<uid(mt)<<", ";

    std::uniform_real_distribution<double> did(0,1);
    for(int i=0;i<10;i++) std::cout<<did(mt)<<", ";
    return 0;
}