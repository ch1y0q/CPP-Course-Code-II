#include <iostream>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// increments the time stored in a Time object by one second
void tick(Time &t)
{
    if (t.second >= 0 && t.second < 59)
        t.setSecond(t.second + 1);
    else {
        t.setSecond(0);
        if (t.minute >= 0 && t.minute < 59)
            t.setMinute(t.minute + 1);
        else {
            t.setMinute(0);
            if (t.hour >= 0 && t.hour < 23)
                t.setHour(t.hour + 1);
            else {
                t.setHour(0);
            }
        }
    }
}

int main()
{
    Time t1; // all arguments defaulted
    Time t2(2); // hour specified; minute and second defaulted
    Time t3(21, 34); // hour and minute specified; second defaulted 
    Time t4(12, 25, 42); // hour, minute and second specified

    cout << "Constructed with:\n\nt1: all arguments defaulted\n  ";
    t1.printUniversal(); // 00:00:00
    cout << "\n  ";
    t1.printStandard(); // 12:00:00 AM

    cout << "\n\nt2: hour specified; minute and second defaulted\n  ";
    t2.printUniversal(); // 02:00:00
    cout << "\n  ";
    t2.printStandard(); // 2:00:00 AM

    cout << "\n\nt3: hour and minute specified; second defaulted\n  ";
    t3.printUniversal(); // 21:34:00
    cout << "\n  ";
    t3.printStandard(); // 9:34:00 PM

    cout << "\n\nt4: hour, minute and second specified\n  ";
    t4.printUniversal(); // 12:25:42
    cout << "\n  ";
    t4.printStandard(); // 12:25:42 PM

    // attempt to initialize t6 with invalid values
    try
    {
        Time t5(27, 74, 99); // all bad values specified
    } // end try
    catch (invalid_argument & e)
    {
        cerr << "\n\nException while initializing t5: " << e.what() << endl;
    } // end catch

    Time t5(23);
    for (int i = 0; i < 4000; ++i) {
        tick(t5);
        t5.printStandard();
        cout << " ";
    }
} // end main