#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		// check sin validity
		if (sin >= min_sin && sin <= max_sin) {
			
			m_sin = sin;

			// store names
			strncpy(m_familyName, familyName, max_name_length + 1);
			strncpy(m_givenName, givenName, max_name_length + 1);

		}
		else {
			strncpy(m_familyName, '\0', max_name_length + 1);
			strncpy(m_givenName, '\0', max_name_length + 1);
			m_sin = 0;
		}
	}

	bool CRA_Account::isEmpty() const {

		if (m_sin >= min_sin && m_sin <= max_sin) {
			return false;
		}
		else {
			return true;
		}
		
	}

	void CRA_Account::display() const {
		if (isEmpty() == false) {
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}



}