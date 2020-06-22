// Ilias Halemi
// 062 111 133
// March 26th, 2018
#include "Account.h"

namespace sict {
	double Account::balance() const {
		return m_balance;
	}

	Account::Account(double newBalance) {
		(newBalance > 0) ? m_balance = newBalance : m_balance = 0.0;
	}

	bool Account::credit(double amount) {
		if (amount > 0) {
			m_balance += amount;
			return true;
		}
		else {
			return false;
		}
	}

	bool Account::debit(double amount) {
		if (amount > 0) {
			m_balance -= amount;
			return true;
		}
		else {
			return false;
		}
	}
} // end of namespace sict
