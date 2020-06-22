// Ilias Halemi
// 062 111 133
// April 13th, 2018
#include <iostream>
#include "Perishable.h"
#include "Product.h"
#include "Date.h"


using namespace std;

namespace AMA {
	Perishable::Perishable() : Product('P') {
		Date();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, false);
		file << "," << expiry();

		if (newLine) {
			file << "\n";
		}

		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);

		if (file.is_open()) {
			int year;
			int month;
			int day;

			file.ignore();
			file >> year;
			file.ignore();
			file >> month;
			file.ignore();
			file >> day;

			m_expiryDate = Date(year, month, day); // copy assign;
		}

		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);

		if (!isClear() || isEmpty()) {
			return os;
		}

		if (linear) {
			os << expiry();
		}
		else {
			os << endl << " Expiry date: " << expiry();
		}

		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		
		Product::read(is); 

		if (isClear()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			Date a; // temp date object
			is >> a;

			if (a.bad()) {

				if (a.errCode() == CIN_FAILED) {
					message("Invalid Price Entry");
				}
				else if (a.errCode() == YEAR_ERROR) {
					message("Invalid Year in Date Entry");
				}
				else if (a.errCode() == MON_ERROR) {
					message("Invalid Month in Date Entry");
				}
				else {
					message("Invalid Day in Date Entry");
				}
				is.setstate(ios::failbit);
			}

			if (!is.fail()) {
			m_expiryDate = a;
			}
		}
		return is;
	}

	const Date& Perishable::expiry() const {
		return m_expiryDate;
	}

} // end of namespace AMA