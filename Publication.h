#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_

#include "Lib.h"
#include "Date.h"
#include "Streamable.h"

namespace sdds {
	class Publication : public Streamable {
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		void setEmpty();
		Publication();
		~Publication();

		// modifiers 
		// ---------
		// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id);
		// Sets the **libRef** attribute value
		void setRef(int value);
		// Sets the date to the current date of the system.
		void resetDate();

		// queries
		// ---------
		//Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;
		//Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;
		//Returns the date attribute
		Date checkoutDate()const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool operator==(const char* title)const;
		//Returns the title attribute
		operator const char* ()const;
		//Returns the libRef attirbute. 
		int getRef()const;

		// streamable pure virtual functions implementation 
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;

		// copy and copy assignment operators
		Publication(const Publication& original);
		Publication& operator=(const Publication& original);
	};
}

#endif
