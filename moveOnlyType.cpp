#include<utility>

class Test {
public:
// = delete; provides a mechanism to suppress the automatic generation
//  of special member functions or to explicitly disallow certain operations,
//  enhancing clarity and enforcing design constraints in your code.
    Test(const Test&) = delete;
    Test& operator =(const Test&) = delete;

    // = default means the complier will synthesize 
    //the default version of the operator
    Test(Test&&) noexcept = default;
    Test& operator=(Test&&) noexcept = default;
    Test() = default;
};
int main() {
    Test test1, test2, test3;

    //Delete special member functions
    //test3 = test2;
   // Test test4(test1);
    Test test4(std::move(test1));
    test3 = std::move(test2);
    return 0;
}