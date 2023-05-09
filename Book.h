/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
Version 1.0
Author	Arina Kolodeznikova
Student ID: 145924213
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {
	class Book : public Publication {
		char* m_author;
	public:
		Book();
		// the rule of three
		~Book();
		Book(const Book& original);
		Book& operator=(const Book& original);
		// methods
		virtual char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		virtual void set(int member_id);
		operator bool() const;
	};
}

#endif
