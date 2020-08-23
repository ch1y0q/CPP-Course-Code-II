#include <iostream>

using namespace std;

class TestException : public runtime_error 
{
public:
    TestException():runtime_error("TestException") {}
};

void g()
{
    try {
        throw TestException();
    }
    catch (...) {
        cout << "Exception caught in function g(). Rethrowing..." << endl;
        throw;
    }
}

int main()
{
    try {
        g();
    }
    catch(TestException& te){
        cout << "Exception caught in function main()" << endl;
    }
    return 0;
}