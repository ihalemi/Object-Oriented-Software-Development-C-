#include "Text.h"

namespace sict {
	Text::Text() {
		m_text = nullptr;
		m_records = 0;
	}

	Text::Text(const std::string file) : m_records(0) {
		std::ifstream f(file);
		

		if (f.is_open()) {
			// variables to count records
			int counter = 0;
			std::string newLine;

			// do while loop to count the number of records 
			do {
				std::getline(f, newLine, '\n');
				counter++;
			} while (!f.fail());
			
			// allocate memory for the number of records in file
			m_text = new std::string[counter];

			f.clear();
			f.seekg(0);

			// copy records to newly allocated memory
			for (int i = 0; i < m_records; i++) {
				std::getline(f, m_text[i], '\n');
			}
			
		}
		else {
			// set to safe empty state
			*this = Text();
		}
	}

	Text::Text(const Text& src) {
		init(src);
	}

	Text& Text::operator=(const Text& src) {
		// check for self-assigment
		if (this != &src) {
			delete[] m_text;
			init(src);
		}
		return *this;
	}

	Text::Text(Text&& src) {
		*this = std::move(src);
	}

	Text& Text::operator=(Text&& src) {
		
		delete[] m_text;
		init(src);
		
		return *this;
	}

	Text::~Text() {
		delete[] m_text;
		m_text = nullptr;
	}

	// logic for copy constructor and operator
	void Text::init(const Text& src) {
		// shallow copy
		m_records = src.m_records;

		// deep copy
		if (src.m_text) {
			// allocate memory
			m_text = new std::string[m_records];
			for (int i = 0; i < m_records; i++) {
				m_text[i] = src.m_text[i];
			}
		}
	}

	// logic for move operator
	void Text::init(Text&& src) {
		if (this != &src) {
			// exchange ownership by assigning memory 
			m_text = src.m_text;
			m_records = src.m_records;

			// delete RValue 
			src.m_text = nullptr;
			src.m_records = 0;
		}
	}

	size_t Text::size() const {
		return m_records;
	}

} // end of namespace sict