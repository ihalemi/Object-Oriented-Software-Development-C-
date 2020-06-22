// Ilias Halemi
// 062 111 133
// March 26th, 2018
#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
	SavingsAccount::SavingsAccount(double balance, double interest) : Account (balance) {
		(interest > 0) ? m_interest = interest : m_interest = 0.0;
	}

	void SavingsAccount::monthEnd() {
		double newBalance = balance() * m_interest;
		credit(newBalance);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account Type: Savings" << endl;
		os.unsetf(ios::floatfield);
		os.precision(2);
		os.setf(ios::fixed, ios::floatfield);
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << (m_interest * 100) << endl;
	}

} // end of namespace sict
