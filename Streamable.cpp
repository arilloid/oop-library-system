/* Citation and Sources...
Final Project Milestone 5
Module: Streamable Interface
Filename: Streamable.cpp
Version 1.0
Author	Arina Kolodeznikova
Student ID: 145924213
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#include "Streamable.h"
using namespace std;

namespace sdds {
	Streamable::~Streamable() {}
	ostream& operator<<(ostream& os, const Streamable& ro) {
		if (ro) {
			ro.write(os);
		}
		return os;
	}
	istream& operator>>(istream& is, Streamable& ro) {
		return (ro.read(is));
	}
}