#include <iostream>
#include "Utils.h"
using namespace std;

namespace sdds {
    int inputMemberNum()
    {
        int value = 0;
        bool valid = false;
        do
        {   
            cin >> value;
            if (cin.fail() || value < 10000 || value > 99999) {
                cout << "Invalid membership number, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else valid = true;
        } while (!valid);
        return value;
    }
}