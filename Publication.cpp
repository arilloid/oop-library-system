/* Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.cpp
Version 1.0
Author	Arina Kolodeznikova
Student ID: 145924213
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Publication.h"
using namespace std;

namespace sdds {
	void Publication::setEmpty() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}
	Publication::Publication() {
		setEmpty();
	}
	Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}
	// modifiers 
	//----------
	// Sets the membership attribute to either zero or a five-digit integer.
	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	// Sets the **libRef** attribute value
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	// Sets the date to the current date of the system.
	void Publication::resetDate() {
		m_date = Date();
	}
	// queries
	//----------
	//Returns the character 'P' to identify this object as a "Publication object"
	char Publication::type()const {
		return 'P';
	}
	//Returns true is the publication is checkout (membership is non-zero)
	bool Publication::onLoan()const {
		return (m_membership != 0);
	};
	//Returns the date attribute
	Date Publication::checkoutDate()const {
		return m_date;
	}
	//Returns true if the argument title appears anywhere in the title of the 
	//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
	bool Publication::operator==(const char* title)const {
		return strstr(m_title, title) != nullptr;
	}
	//Returns the title attribute
	Publication::operator const char* ()const {
		return m_title;
	}
	//Returns the libRef attirbute. 
	int Publication::getRef()const {
		return m_libRef;
	}
	// streamable pure virtual functions implementation 
	bool Publication::conIO(ios& io)const {
		return &io == &std::cin || &io == &std::cout;
	}
	ostream& Publication::write(ostream& os) const {
		char printTitle[SDDS_TITLE_WIDTH + 1] = { 0 };
		strncpy(printTitle, m_title, SDDS_TITLE_WIDTH);

		if (conIO(os)) {
			os << "| " << m_shelfId;
			os << " | " << setw(SDDS_TITLE_WIDTH) << left << setfill('.') << printTitle << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | " << m_date << " |";
		}
		else {
			os << type();
			os << "\t" << m_libRef;
			os << "\t" << m_shelfId;
			os << "\t" << m_title;
			os << "\t" << m_membership;
			os << "\t" << m_date;
		}
		return os;
	}

	istream& Publication::read(istream& istr) {
		Publication temp;
		char tempTitle[256 + 1] = { '\0' };
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		setEmpty();
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(temp.m_shelfId, SDDS_SHELF_ID_LEN + 1);
			if (strlen(temp.m_shelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.getline(tempTitle, 256);
			temp.m_title = new char[strlen(tempTitle) + 1];
			strcpy(temp.m_title, tempTitle);
			cout << "Date: ";
			istr >> temp.m_date;
		}
		else {
			istr >> temp.m_libRef;
			istr.ignore();
			istr.getline(temp.m_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(tempTitle, 256, '\t');
			temp.m_title = new char[strlen(tempTitle) + 1];
			strcpy(temp.m_title, tempTitle);
			istr >> temp.m_membership;
			istr.ignore();
			istr >> temp.m_date;
		}
		if (!temp.m_date) {
			istr.setstate(ios::failbit);
		}
		if (istr) {
			*this = temp;
		}
		return istr;
	}
	Publication::operator bool() const {
		return (m_title != nullptr && m_shelfId[0] != '\0');
	}

	// copy constructor and copy assignment operator
	Publication::Publication(const Publication& orig) {
		*this = orig;
	}
	Publication& Publication::operator=(const Publication& orig) {
		strcpy(m_shelfId, orig.m_shelfId);
		set(orig.m_membership);
		setRef(orig.m_libRef);
		m_date = orig.m_date;
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		if (orig.m_title != nullptr) {
			m_title = new char[strlen(orig.m_title) + 1];
			strcpy(m_title, orig.m_title);
		}
		return *this;
	}
}