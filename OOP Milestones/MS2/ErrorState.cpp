// Ilias Halemi
// 062 111 133
// March 20th, 2018

#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace AMA {

	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage != nullptr) {
			m_errorMessage = new char[strlen(errorMessage) + 1];
			strcpy(m_errorMessage, errorMessage);
		}
		else {
			m_errorMessage = nullptr;
		}
	}

	ErrorState::~ErrorState() {
		clear();
	}

	void ErrorState::clear() {
		delete[] m_errorMessage;
		m_errorMessage = nullptr;
	}

	bool ErrorState::isClear() const {
		return (m_errorMessage == nullptr);
	}

	void ErrorState::message(const char* str) {
		delete[] m_errorMessage;
		m_errorMessage = new char[strlen(str) + 1];
		strcpy(m_errorMessage, str);
	}

	const char* ErrorState::message() const {
		return m_errorMessage;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& a) {
		if (!a.isClear()) {
			os << a.message();
		}
		return os;
	}

} // end of namespace AMA