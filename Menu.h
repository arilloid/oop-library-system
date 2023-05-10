#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>

namespace sdds {
	const int MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem {
		char* m_item;
		MenuItem(const char* item = nullptr);
		MenuItem(const MenuItem& source) = delete;
		MenuItem& operator=(const MenuItem& source) = delete;
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		std::ostream& display(std::ostream& os = std::cout) const;
		friend class Menu;
	};
	class Menu {
		char* m_title;
		MenuItem m_items[MAX_MENU_ITEMS];
		int item_cnt;
	public:
		Menu();
		Menu(const char* title);
		Menu(const Menu& source) = delete;
		Menu& operator=(const Menu& source) = delete;
		~Menu();
		std::ostream& displayTitle(std::ostream& os = std::cout) const;
		std::ostream& displayMenu(std::ostream& os = std::cout) const;
		unsigned int run() const;
		unsigned int operator~() const;
		Menu& operator<<(const char* menuitemContent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](int index) const;
	};
	std::ostream& operator<<(std::ostream&, const Menu& menu);
}

#endif 
