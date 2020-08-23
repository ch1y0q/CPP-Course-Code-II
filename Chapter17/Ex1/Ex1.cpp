#include <iostream>

using namespace std;

// define an exception class
class TestException : public runtime_error
{
public:
    TestException(const char* s) :runtime_error(s) {}
};

// perform division and throw DivideByZeroException object if 
// divide-by-zero exception occurs
double quotient(int numerator, int denominator)
{
    // throw DivideByZeroException if trying to divide by zero
    if (denominator == 0)
        throw TestException("Cannot be divided by zero."); // terminate function

     // return division result
    return static_cast<double>(numerator) / denominator;
} // end function quotient

int main()
{
    int number1; // user-specified numerator
    int number2; // user-specified denominator

    cout << "Enter two integers (end-of-file to end): ";

    // enable user to enter two integers to divide
    while (cin >> number1 >> number2)
    {
        // try block contains code that might throw exception
        // and code that will not execute if an exception occurs
        try
        {
            double result = quotient(number1, number2);
            cout << "The quotient is: " << result << endl;
        } // end try
        catch (TestException& exception)
        {
            cout << "Exception occurred: "
                << exception.what() << endl;
            throw;      // rethrow
            // ABORT
        } // end catch

        cout << "\nEnter two integers (end-of-file to end): ";
    } // end while
    cout << endl;
} // end main