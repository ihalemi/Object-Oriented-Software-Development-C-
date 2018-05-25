// Ilias Halemi
// 062 111 133
// May 9th, 2018

#ifndef W1_CSTRING_H
#define W1_CSTRING_H
#define MAX_CHAR 3
#include <iostream>

namespace w1 {
	class CString {
		char m_string[MAX_CHAR + 1];

	public:
		CString(const char* string);
		void display(std::ostream& os) const;
	};
	std::ostream &operator<<(std::ostream& os, const CString& string);
}
#endif // !W1_CSTRING_H

