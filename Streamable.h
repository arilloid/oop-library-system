/* Citation and Sources...
Final Project Milestone 5
Module: Streamable Interface
Filename: Streamable.h
Version 1.0
Author	Arina Kolodeznikova
Student ID: 145924213
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>

namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual bool conIO(std::ios&) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable();
	};
	std::ostream& operator<<(std::ostream& os, const Streamable& ro);
	std::istream& operator>>(std::istream& is, Streamable& ro);
}

#endif
