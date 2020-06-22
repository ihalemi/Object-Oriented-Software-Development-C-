#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {
	Contact::Contact() {
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_size = 0;
	}

	Contact::Contact(const char* name, long long* phoneNumbers, int size) {
		// Variable to track size of phone number array
		int j = 0;

		// Validation
		if (phoneNumbers != nullptr || size > 0 || name[0] != '\0' || name != nullptr) {
			strncpy(m_name, name, 19);
			m_phoneNumbers = new long long[size];

			// Validate and copy phone numbers
			for (int i = 0; i < size; i++) {

				// Format Phone Number
				long long countryCode = (phoneNumbers[i] / 10000000000);              // (+1)
				long long areaCode = ((phoneNumbers[i] % 10000000000) / 10000000);   // (416)
				long long number = (phoneNumbers[i] % 10000000);	                  // (237-1234)

				if ((countryCode < 100 && countryCode != 0) && (areaCode > 0 && areaCode < 1000 && areaCode > 99)
					&& (number < 10000000 && number > 0)) {
					m_phoneNumbers[j] = phoneNumbers[i];
					j++;
				}
			}
		}
		else {
				*this = Contact();
			}
		// Assign m_size the number of phone numbers in array
		m_size = j;
	}

	Contact::~Contact() {
		delete[] m_phoneNumbers;
	}

	bool Contact::isEmpty() const {
		return (m_name[0] == '\0' || (m_phoneNumbers == nullptr && m_size == 0));
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << m_name << endl;

			for (int i = 0; i < m_size; i++) {

				// Format Phone Number
				long long countryCode = (m_phoneNumbers[i] / 10000000000);              // (+1)
				long long areaCode = ((m_phoneNumbers[i] % 10000000000) / 10000000);   // (416)
				int number = (m_phoneNumbers[i] % 10000000);	                  // (237-1234)
				int number1 = (number / 10000);
				int number2 = (number % 10000);

				cout << "(+" << countryCode << ") " << areaCode << " " << number1 << "-" << setfill('0') << setw(4) << number2 << endl;
			}
		}
	}

	Contact::Contact(const Contact& src) {
		m_phoneNumbers = nullptr;
		*this = src; // call assigment operator to minimize code duplication
	}

	Contact& Contact::operator=(const Contact& a) {
		// Check for self-assigment
		if (this != &a) {
			
			m_size = a.m_size;
			strcpy(m_name, a.m_name);

			delete[] m_phoneNumbers;

			if (a.m_phoneNumbers != nullptr) {
				m_phoneNumbers = new long long[m_size];

				for (int i = 0; i < m_size; i++) {
					m_phoneNumbers[i] = a.m_phoneNumbers[i];
				}
			}
			else {
				m_phoneNumbers = nullptr;
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(long long phoneNumber) {
		// Validate phone number
		long long countryCode = (phoneNumber / 10000000000);              // (+1)
		long long areaCode = ((phoneNumber % 10000000000) / 10000000);   // (416)
		long long number = (phoneNumber % 10000000);	                  // (237-1234)

		if ((countryCode < 100 && countryCode != 0) && (areaCode > 0 && areaCode < 1000 && areaCode > 99)
			&& (number < 10000000 && number > 0)) {
			
			m_size += 1;

				long long* temp;
				temp = new long long[m_size];
				for (int i = 0; i < (m_size - 1); i++) {
					temp[i] = m_phoneNumbers[i];
				}
				delete[] m_phoneNumbers;
				m_phoneNumbers = temp;
		}
		else {
			m_phoneNumbers = new long long[m_size];
		}
		m_phoneNumbers[m_size - 1] = phoneNumber;

		return *this;
	}

} // END OF WORKSHOP