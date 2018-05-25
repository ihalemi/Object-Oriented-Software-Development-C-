#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <iostream>
#include <string>
#include <fstream>

namespace sict {
	class Text {
		// array of strings holding file name 
		std::string* m_text;
		// amount of records 
		int m_records;

	public:
		Text();
		Text(const std::string);

		// copy constructor and operator
		Text(const Text&);
		Text& operator=(const Text&);
		// move constructor and operator
		Text(Text&&);
		Text& operator=(Text&&);
		
		~Text();

		// resource handling for copy constructor and operator
		void init(const Text&);
		// resource handling for move constructor and operator
		void init(Text&&);
		size_t size() const;

	};
}
#endif // !SICT_TEXT_H

