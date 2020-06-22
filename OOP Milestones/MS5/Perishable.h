// Ilias Halemi
// 062 111 133
// April 13th, 2018
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include <iostream>
#include <fstream>
#include "Product.h"
#include "Date.h"

namespace AMA {
	class Perishable : public Product {
		Date m_expiryDate;

	public:
		Perishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}

#endif // !AMA_PERISHABLE_H

