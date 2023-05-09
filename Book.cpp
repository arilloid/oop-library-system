/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
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
#include "Book.h"
using namespace std;

namespace sdds {
	Book::Book() :Publication() {
		m_author = nullptr;
	}
	// the rule of three
	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}
	Book::Book(const Book& original) : Publication(original) {
		if (m_author) {
			delete[] m_author;
			m_author = nullptr;
		}
		m_author = new char[strlen(original.m_author) + 1];
		strcpy(m_author, original.m_author);
	}
	Book& Book::operator=(const Book& original) {
		Publication::operator=(original);
		if (m_author) {
			delete[] m_author;
			m_author = nullptr;
		}
		if (original.m_author) {
			m_author = new char[strlen(original.m_author) + 1];
			strcpy(m_author, original.m_author);
		}
		return *this;
	}
	// methods
	char Book::type()const {
		return 'B';
	}
	ostream& Book::write(ostream& os) const {
		Publication::write(os);
		if (conIO(os)) {
			char printAuthor[SDDS_AUTHOR_WIDTH + 1] = { '\0' };
			strncpy(printAuthor, m_author, SDDS_AUTHOR_WIDTH);
			os << " " << setw(SDDS_AUTHOR_WIDTH) << setfill(' ') << left << printAuthor << " |";
		}
		else {
			os << "\t" << m_author;
		}
		return os;
	}
	istream& Book::read(istream& istr) {
		char tempAuthor[256 + 1] = { '\0' };

		Publication::read(istr);

		if (m_author) {
			delete[] m_author;
			m_author = nullptr;
		}

		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
		}
		else {
			istr.ignore(1000, '\t');
		}

		istr.get(tempAuthor, 256);

		if (istr) {
			m_author = new char[strlen(tempAuthor) + 1];
			strcpy(m_author, tempAuthor);
		}

		return istr;
	}
	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}
	Book::operator bool() const {
		return (m_author && Publication::operator bool());
	}
}