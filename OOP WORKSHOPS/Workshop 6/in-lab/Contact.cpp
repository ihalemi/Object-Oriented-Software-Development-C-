#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {
	Contact::Contact() {
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
	}

	Contact::Contact(const char* name, long long* phoneNumbers, int size) {
	
		// Validate and assign name
		if (name != nullptr && name[0] != '\0') {
			strncpy(m_name, name, 19);
		}

		// Allocate Dynamic Memory
		if (phoneNumbers != nullptr) {
			m_phoneNumbers = new long long[size];
		}

		int j = 0;

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
		// Assign m_size the number of phone numbers in array
		m_size = j;
	}

	Contact::~Contact() {
		delete[] m_phoneNumbers;
	}

	bool Contact::isEmpty() const {
		return ((m_name[0] == '\0' || m_name == nullptr) && m_phoneNumbers == nullptr);
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
}