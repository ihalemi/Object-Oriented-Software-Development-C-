// Name: Ilias Halemi
// Email: ihalemi@myseneca.ca
// Student ID: 062 111 133
// Date: 2/6/2018

#include <iostream>
#include <cstring>
#include <iomanip>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		// valid Canadian SIN
		int checkNumber = sin % 10;
		int secondDigit = (sin / 10) % 10;
		int thirdDigit = ((sin / 100) % 100) % 10;
		int fourthDigit = ((sin / 1000) % 1000) % 10;
		int fifthDigit = ((sin / 10000) % 10000) % 10;
		int sixthDigit = ((sin / 100000) % 100000) % 10;
		int seventhDigit = ((sin / 1000000) % 1000000) % 10;
		int eightDigit = ((sin / 10000000) % 10000000) % 10;
		int ninethDigit = (sin / 100000000) % 100000000;


		int sum1 = ((secondDigit + secondDigit) % 10);
		int sum2 = ((secondDigit + secondDigit) / 10) % 10;

		int sum3 = ((fourthDigit + fourthDigit) % 10);
		int sum4 = ((fourthDigit + fourthDigit) / 10) % 10;

		int sum5 = ((sixthDigit + sixthDigit) % 10);
		int sum6 = ((sixthDigit + sixthDigit) / 10) % 10;

		int sum7 = ((eightDigit + eightDigit) % 10);
		int sum8 = ((eightDigit + eightDigit) / 10) % 10;

		int total = (sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8) + (thirdDigit + fifthDigit + seventhDigit + ninethDigit);

		int nextMultiple = total + (10 - (total % 10));

		int difference = nextMultiple - total;

		// check 9 digit SIN validity
		if (sin >= min_sin && sin <= max_sin && familyName != '\0' && givenName != '\0' && difference == checkNumber) {
			
			m_sin = sin;
			// store names
			strncpy(m_familyName, familyName, max_name_length + 1);
			strncpy(m_givenName, givenName, max_name_length + 1);

			m_taxYears = 0;

		}
		else {
			strncpy(m_familyName, "", max_name_length + 1);
			strncpy(m_givenName, "", max_name_length + 1);
			m_sin = 0;
		}
	}

	bool CRA_Account::isEmpty() const {

		if (m_sin >= min_sin && m_sin <= max_sin && m_familyName[0] != '\0' && m_givenName[0] != '\0') {
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

			// At-Home
			for (int i = 0; i < max_yrs; i++) {

				if (m_balanceRefund[i] > 2) {
					cout << "Year (" << m_taxReturnYrs[i] << ") balance owing: " << m_balanceRefund[i] << endl;
				}
				else if (m_balanceRefund[i] < 0 && m_balanceRefund[i] < -2) {
					//unsigned balance = m_balanceRefund[i];
					// balance = balance + 2468;

					cout << "Year (" << m_taxReturnYrs[i] << ") refund due: " << fixed << setprecision(2) << m_balanceRefund[i] * -1 << endl;
				}
				else {
					cout << "Year (" << m_taxReturnYrs[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	// At-Home
	void CRA_Account::set(int year, double balance) {

			if (m_taxYears < max_yrs && isEmpty() == false) {

				m_taxReturnYrs[m_taxYears] = year;
				m_balanceRefund[m_taxYears] = balance;
				m_taxYears++;
			
			}
		}
	}
// END OF WORKSHOP