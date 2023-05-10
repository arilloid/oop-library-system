#include "Streamable.h"
using namespace std;

namespace sdds {
	Streamable::~Streamable() {}
	ostream& operator<<(ostream& os, const Streamable& ro) {
		if (ro) {
			ro.write(os);
		}
		return os;
	}
	istream& operator>>(istream& is, Streamable& ro) {
		return (ro.read(is));
	}
}