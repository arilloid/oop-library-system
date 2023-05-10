#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Menu.h"
using namespace std;

namespace sdds {
	MenuItem::MenuItem(const char* item) {
		if (item) {
			m_item = new char[strlen(item) + 1];
			strcpy(m_item, item);
		}
		else {
			m_item = nullptr;
		}
	}
	MenuItem::~MenuItem() {
		delete[] m_item;
		m_item = nullptr;
	}
	MenuItem::operator bool() const {
		return (m_item != nullptr);
	}
	MenuItem::operator const char* () const {
		return m_item;
	}
	ostream& MenuItem::display(ostream& os) const {
		if (*this) {
			os << m_item;
		}
		return os;
	}

	Menu::Menu() {
		m_title = nullptr;
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			m_items[i].m_item = nullptr;
		}
		item_cnt = 0;
	}
	Menu::Menu(const char* title) {
		if (title) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		else {
			m_title = nullptr;
		}
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			m_items[i].m_item = nullptr;
		}
		item_cnt = 0;
	}
	Menu::~Menu() {
		delete[] m_title;
		m_title = nullptr;
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			delete[] m_items[i].m_item;
			m_items[i].m_item = nullptr;
		}
	}
	ostream& Menu::displayTitle(ostream& os) const {
		if (m_title) {
			os << m_title;
		}
		return os;
	}
	ostream& Menu::displayMenu(ostream& os) const {
		if (m_title) {
			os << m_title << endl;
		}
		for (int i = 0; i < item_cnt; i++) {
			os << " " << i + 1 << "- ";
			os << m_items[i].m_item << endl;
		}
		os << " 0- Exit" << endl;
		os << "> ";
		return os;
	}
	unsigned int Menu::run() const {
		int num;
		bool isNumeric = false;
		displayMenu();
		do {
			if (cin >> num) {
				isNumeric = true;
			}
			cin.clear();
			cin.ignore(10000, '\n');
		} while ((!isNumeric || num < 0 || num > item_cnt) &&
			cout << "Invalid Selection, try again: ");
		return num;
	}
	unsigned int Menu::operator~() const {
		return run();
	}
	Menu& Menu::operator<<(const char* menuitemContent) {
		if (item_cnt < MAX_MENU_ITEMS) {
			if (menuitemContent) {
				this->m_items[item_cnt].m_item = new char[strlen(menuitemContent) + 1];
				strcpy(this->m_items[item_cnt].m_item, menuitemContent);
			}
			item_cnt++;
		}
		return *this;
	}
	Menu::operator int() const {
		return item_cnt;
	}
	Menu::operator unsigned int() const {
		return item_cnt;
	}
	Menu::operator bool() const {
		return (item_cnt >= 1);
	}
	const char* Menu::operator[](int index) const {
		if (index > item_cnt) {
			index = index % item_cnt;
		}
		return (const char*)(m_items[index]);
	}
	ostream& operator<<(ostream& os, const Menu& menu) {
		menu.displayTitle(os);
		return os;
	}
}