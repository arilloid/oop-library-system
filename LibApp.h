/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
Version 1.0
Author	Arina Kolodeznikova
Student ID: 145924213
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_LIBAPP_H_
#define SDDS_LIBAPP_H_

#include "Menu.h"
#include "Publication.h"
#include "PublicationSelector.h"

namespace sdds {
	class LibApp {
		char filename[256];
		Publication* publications[SDDS_LIBRARY_CAPACITY];
		int noOfPubls;
		int lastRefNum;
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		Menu m_pubMenu;
		bool confirm(const char* message);
		void load();
		void save() const;
		int search(int searchType);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
		// added functions
		void allSearch(PublicationSelector& pbs, const char* title, const char pubType);
		void onLoanSearch(PublicationSelector& pbs, const char* title, const char pubType);
		void notOnLoanSearch(PublicationSelector& pbs, const char* title, const char pubType);
		Publication* getPubByLibRef(int libRefNum);
	public:
		LibApp(const char* file);
		~LibApp();
		void run();
	};
}

#endif
