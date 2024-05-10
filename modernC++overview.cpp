#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


void universal_initializer() {
    //Universal Initializer
    int x{7};
    std::string str{"Hello World"};
    //int x{7.7}; Illegal
    std::vector<int> vec{4,3,2,1};

    std::cout<<" x = "<< x << "\nstr = "<< str ;
    std::cout<<"\n vec = ";
    for(std::vector<int>::iterator it =vec.begin();it!=vec.end();++it) std::cout<<*it<<", ";

    //auto type specifier
    std::vector<std::string> vecStr{"Shrey", "Manansu"};
    std::cout<<"\n vecStr = ";
    for(auto it = vecStr.begin();it != vecStr.end(); ++ it) std::cout<<*it <<", ";

    //Modify the vector
     for(auto& i: vec) {
        i += 2;
    }
    for(auto i: vec) {
        std::cout<< i << ", ";
    }
}
void lambda_expression() {
    int n = 5;
    int a = 1, b = 2, c = 3;
    //capture [] - lambda body contains immutable copy of local variable
    auto lam = [&n] (int arg) {return ++n * arg;};
    std::cout << "\nlambda invoked ::" << lam(3) << "\n n = " << n;

    //Capture all variable in scope
    //capture by value
    [=](){std::cout << "\na ="<<a<< "b ="<<b<< "c ="<<c;}();
    //Capture by reference
    [&](){a++;b++;c++;}();
    std::cout <<"\nAfter lambda reference "<< "a ="<<a<< "b ="<<b<< "c ="<<c;

    //Selective capture
    //[=,&n]{}();
    //[&,=a,=b]{}();

    //to access data members
    //[this]() {return data_members % 2;};
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    int radix = 3;
    auto n_radix = std::count_if(vec.begin(), vec.end(),
        [radix] (int n) { return (n % radix==0);});
    
    std::cout<< "\n n_radix" <<n_radix;

}
void lambda_expression_captureByMove() {
    std::vector<std::string> str(5);
    std::cout << "\nCapture by reference ::\n";
    [&str]() {
        std::cout << "size in lambda = " << str.size();
    }();
    std::cout << "\nAfter Lambda Capture by reference ::\n";
    std::cout << "size in lambda = " << str.size();
//  ---------------------------------------------------
    std::cout<< "\nUse of move in capute\n";
    std::cout << "\nCapture by reference ::\n";
    [vec_strings = std::move(str)]() {
        std::cout << "size in lambda = " << vec_strings.size();
    }();
    std::cout << "\nAfter Lambda Capture by reference ::\n";
    std::cout << "size in lambda = " << str.size();


}
void func_rValue(int&& x,std::vector<int>&& vec) {
    std::cout<< "\nRvalue reference" << std:: endl;
    std::cout<< "Vec size" << vec.size();

}

int main() {
    // universal_initializer();
    // lambda_expression();
    lambda_expression_captureByMove();
    std::vector<int> vec_rvalue(10000);
    func_rValue(2,std::move(vec_rvalue)); //memory optimization, no copy would be made directly value with be change
    //rvalue reference is similar yet different than call by reference
    int y = 2;
    //func_rValue(y); //Error!must be a movable rvalue Cannot convert argument 1 from 'int' to 'int&&'.
    //You cannot bind an lvalue to rvalue references
    return 0;
}