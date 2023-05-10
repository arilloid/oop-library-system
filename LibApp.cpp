#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Book.h"
#include "LibApp.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	LibApp::LibApp(const char* file): m_mainMenu("Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_pubMenu("Choose the type of publication:") {
		strcpy(filename, file);
		noOfPubls = 0;
		lastRefNum = 0;
		m_changed = false;
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_pubMenu << "Book";
		m_pubMenu << "Publication";
		load();
	}
	bool LibApp::confirm(const char* message) {
		int input = 0;
		Menu confirmMenu(message);
		confirmMenu << "Yes";
		input = confirmMenu.run();
		return (input == 1);
	}	
	void LibApp::load() {
		int i = 0;
		char type;
		ifstream infile(filename);
		std::cout << "Loading Data" << endl;
		for (i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {
			infile >> type;
			infile.ignore();
			if (infile) {
				if (type == 'P') {
					publications[i] = new Publication;
				}
				else if (type == 'B') {
					publications[i] = new Book;
				}
				infile >> *publications[i];
				noOfPubls++;
			}
		}
		lastRefNum = publications[noOfPubls - 1]->getRef();
	}
	void LibApp::save() const {
		std::cout << "Saving Data" << endl;
		ofstream onfile(filename);
		for (int i = 0; i < noOfPubls; i++) {
			if (publications[i]->getRef()) {
				onfile << *publications[i] << endl;
			}
		}
		onfile.close();
	}
	int LibApp::search(int searchType) {
		int selection, libRefNum = 0;
		char title[256 + 1] = {'\0'};
		bool aborted = false;
		PublicationSelector pubSelector("Select one of the following found matches:", 15);
		selection = m_pubMenu.run();
		cout << "Publication Title: ";
		cin.getline(title, 256);
		if (selection) {
			if (searchType == 1) {
				if (selection == 1) {
					allSearch(pubSelector, title, 'B');
				}
				else if (selection == 2) {
					allSearch(pubSelector, title, 'P');
				}
			}
			else if (searchType == 2) {
				if (selection == 1) {
					onLoanSearch(pubSelector, title, 'B');
				}
				else if (selection == 2) {
					onLoanSearch(pubSelector, title, 'P');
				}
			}
			else if (searchType == 3) {
				if (selection == 1) {
					notOnLoanSearch(pubSelector, title, 'B');
				}
				else if (selection == 2) {
					notOnLoanSearch(pubSelector, title, 'P');
				}
			}
			if (pubSelector) {
				pubSelector.sort();
				libRefNum = pubSelector.run();
				if (libRefNum > 0) {
					std::cout << *getPubByLibRef(libRefNum) << endl;
				}
				else aborted = true;
			}
			else std::cout << "No matches found!" << endl;
		}
		else aborted = true;
		if (aborted) {
			cout << "Aborted!" << endl;
		}
		return libRefNum;
	}
	void LibApp::returnPub() {
		int libRefNum, daysOnLoan, lateDays;
		double penalty;
		Publication* publication = nullptr;
		std::cout << "Return publication to the library" << endl;
		libRefNum = search(2);
		if (libRefNum && confirm("Return Publication?")) {
			publication = getPubByLibRef(libRefNum);
			daysOnLoan = Date() - publication->checkoutDate();
			if (daysOnLoan > SDDS_MAX_LOAN_DAYS) {
				lateDays = daysOnLoan - SDDS_MAX_LOAN_DAYS;
				penalty = lateDays * 0.5;
				std::cout << "Please pay $" << fixed << setprecision(2) << penalty << " penalty for being "
					<< lateDays << " days late!" << endl;
			}
			publication->set(0);
			m_changed = true;
			std::cout << "Publication returned" << endl;
		}
	}
	void LibApp::newPublication() {
		int pubType;
		Publication* newPublication = nullptr;
		if (noOfPubls == SDDS_LIBRARY_CAPACITY){
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			std::cout << "Adding new publication to the library" << endl;
			pubType = m_pubMenu.run();
			if (pubType) {
				if (pubType == 1) newPublication = new Book;
				else if (pubType == 2) newPublication = new Publication;
				cin >> *newPublication;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					std::cout << "Aborted!" << endl;
				}
				else {
					if (confirm("Add this publication to the library?")) {
						if (*newPublication) {
							m_changed = true;
							lastRefNum++;
							publications[noOfPubls] = newPublication;
							noOfPubls++;
							newPublication->setRef(lastRefNum);
							std::cout << "Publication added" << endl;
						}
						else {
							std::cout << "Failed to add publication!" << endl;
						}
					}
					else std::cout << "Aborted!" << endl;
				}
			}
			else std::cout << "Aborted!" << endl;
		}
	}
	void LibApp::removePublication() {
		int libRefNum ;
		std::cout << "Removing publication from the library" << endl;
		libRefNum = search(1);
		if (libRefNum && confirm("Remove this publication from the library?")) {
			getPubByLibRef(libRefNum)->setRef(0);
			m_changed = true;
			std::cout << "Publication removed" << endl;
		}
	}
	void LibApp::checkOutPub() {
		int memberNum;
		std::cout << "Checkout publication from the library" << endl;
		int libRefNum = search(3);
		if (libRefNum && confirm("Check out publication?")) {
			m_changed = true;
			std::cout << "Enter Membership number: ";
			memberNum = inputMemberNum();
			getPubByLibRef(libRefNum)->set(memberNum);
			std::cout << "Publication checked out" << endl;
		}
	}
	void LibApp::run() {
		int selection, saveSelect;
		do
		{
			selection = m_mainMenu.run();
			switch (selection) {
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			case 0:
				if (m_changed) {
					saveSelect = m_exitMenu.run();
					if (saveSelect == 1) {
						save();
					}
					else if (saveSelect == 2) {
						selection = 1;
					}
					else {
						if (!confirm("This will discard all the changes are you sure?")) {
							selection = 1;
						}
					}
				}
				break;
			}
			std::cout << endl;
		} while (selection);
		std::cout << "-------------------------------------------" << endl;
		std::cout << "Thanks for using Seneca Library Application" << endl;
	}
	// added functions
	LibApp::~LibApp() {
		for (int i = 0; i < noOfPubls; i++) {  
			delete publications[i];
		}
	}
	void LibApp::allSearch(PublicationSelector& pbs, const char* title, const char pubType) {
		for (int i = 0; i < noOfPubls; i++) {
			if (publications[i]->getRef() && publications[i]->type() == pubType
				&& *publications[i] == title) {
				pbs << publications[i];
			}
		}
	}
	void LibApp::onLoanSearch(PublicationSelector& pbs, const char* title, const char pubType) {
		for (int i = 0; i < noOfPubls; i++) {
			if (publications[i]->onLoan() && publications[i]->getRef()
				&& publications[i]->type() == pubType && *publications[i] == title) {
				pbs << publications[i];
			}
		}
	}
	void LibApp::notOnLoanSearch(PublicationSelector& pbs, const char* title, const char pubType) {
		for (int i = 0; i < noOfPubls; i++) {
			if (!publications[i]->onLoan() && publications[i]->getRef()
				&& publications[i]->type() == pubType && *publications[i] == title) {
				pbs << publications[i];
			}
		}
	}
	Publication* LibApp::getPubByLibRef(int libRefNum) {
		int index = 0;
		for (int i = 0; i < noOfPubls; i++)
		{
			if (publications[i]->getRef() == libRefNum) {
				index = i;
			}
		}
		return publications[index];
	}
}