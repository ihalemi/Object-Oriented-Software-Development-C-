// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

// Ilias Halemi
// 062 111 133
// March 30th, 2018
#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthFee) : Account(balance) {
		transactionFee > 0 ? m_transactionFee = transactionFee : m_transactionFee = 0.0;

		monthFee > 0 ? m_monthFee = monthFee : m_monthFee = 0.0;
	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double amount) {
		Account::debit(m_transactionFee);
		return Account::credit(amount);
	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double amount) {
		return Account::debit(amount + m_transactionFee);
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		Account::debit(m_monthFee + m_transactionFee);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os.unsetf(ios::floatfield);
		os.precision(2);
		os.setf(ios::fixed, ios::floatfield);
		os << "Balance: $" << balance() << endl;
		os << "Per Transaction Fee: " << m_transactionFee << endl;
		os << "Monthly Fee: " << m_monthFee << endl;
	}

} // end of namespace sict 