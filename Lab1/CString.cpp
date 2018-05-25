#include "CString.h"
#include <iostream>

// a global int of static duration; lasts the entire lifetime of program
static int a = 0;

namespace w1 {
	CString::CString(const char* string) {

		for (int i = 0; i < MAX_CHAR; i++) {
			if (string[i] != '\0') {
				m_string[i] = string[i];
			}
			else {
				m_string[i] = '\0';
			}
		}
	}

	void CString::display(std::ostream& os) const {
		for (int i = 0; i < MAX_CHAR; i++) {
			if (m_string[i] != '\0') {
				os << m_string[i];
			}
		}
	}

	std::ostream &operator<<(std::ostream& os, const CString& string) {
		os << a++ << ": ";
		string.display(os);
		return os;
	}
} // end of namespace w1