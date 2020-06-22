// Name: Ilias Halemi
// Email: ihalemi@myseneca.ca
// Student ID: 062 111 133
// Date: 2/6/2018

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


namespace sict {

	// Constants
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {

		char m_familyName[max_name_length + 1];
		char m_givenName[max_name_length + 1];
		int m_sin;

		// At-Home
		int m_taxReturnYrs[max_yrs];
		double m_balanceRefund[max_yrs];
		int m_taxYears;


	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const; // query
		void display() const; // query

		// At-Home
		void set(int year, double balance);

	};

}

#endif