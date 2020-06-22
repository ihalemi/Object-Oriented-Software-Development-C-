// Ilias Halemi
// 062 111 133
// March 30th, 2018
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include <iostream>
#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
		double m_transactionFee;
		double m_monthFee;

		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);

			// TODDO: credit adds +ve amount to the balance
			bool credit(double);

			// TODO: debit subtracts a +ve amount from the balance
			bool debit(double);

			// TODO: month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif
