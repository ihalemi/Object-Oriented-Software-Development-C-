// Ilias Halemi
// 062 111 133
// March 26th, 2018
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
	const double interestRate = 0.05;
	const double transactionFee = 0.50;
	const double monthFee = 2.00;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* p = nullptr;

		if (type[0] == 'S') {
			p = new SavingsAccount(balance, interestRate);
		}
		else if (type[0] == 'C') {
			p = new ChequingAccount(balance, transactionFee, monthFee);
		}
		return p;
	}

} // end of namespace sict
