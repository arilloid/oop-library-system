/* Citation and Sources...
Final Project Milestone 5
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Arina Kolodeznikova
Student ID: 145924213
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

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