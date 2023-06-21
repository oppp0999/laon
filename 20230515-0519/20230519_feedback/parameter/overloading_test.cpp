#include <iostream>

class Test
{
private:
    int abc;
public:
  Test(int a){
        abc = a;
    }

    friend std::ostream& operator<< (std::ostream& os, const Test& test_info){
        os << "test : " << test_info.abc;
        return os;
    }
};

int main(){
    Test test(10);

    std::cout << test;

    return 0;
}