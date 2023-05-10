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
