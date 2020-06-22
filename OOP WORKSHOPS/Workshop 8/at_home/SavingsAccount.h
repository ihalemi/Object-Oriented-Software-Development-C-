// Ilias Halemi
// 062 111 133
// March 26th, 2018
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double m_interest;
	public:
		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

		// TODO: perform month end transactions
		void monthEnd();

		// TODO: display inserts the account information into an ostream			
		void display(std::ostream&) const;
	};
}
#endif
