#include<iostream>
#include<thread>
#include<vector> 

int main() {
    std::vector<std::string> vec{"Shrey", "Manansvi", "Anish", "Utkarsh"};
    auto lamPrint = [](std::string name,std::string num){
        std::cout << name << " says " << num << std::endl;
    };
    auto decide = [](int n) { 
        if(n%3 == 0 && n%5 == 0) return std::string("fizzbuzz");
        else if(n%3 == 0) return std::string("fizz");
        else if(n%5 == 0) return std::string("buzz");
        else return std::to_string(n); 
    };
    auto playFizzBuzz = [vec,lamPrint,decide](){

        for(int i =0;i<20;i++) {
            lamPrint(vec.at(i%vec.size()),decide(i+1));
        }
    };
    std::thread game{playFizzBuzz};
    game.join();
    return 0;
}