// Ilias Halemi
// 062 111 133
// March 22, 2018

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <iostream>
#include "ErrorState.h"

namespace AMA {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Product : public ErrorState {
		char m_type; // type of product for use in file
		char m_sku[max_sku_length + 1]; // product's sku
		char m_unit[max_unit_length + 1]; // product's units
		char* m_name; // name of the product
		int m_qty; // current units on hand
		int m_qtyNeeded; // units needed
		double m_price; // price of a single product before tax
		bool m_taxable; // if product is taxable 
		ErrorState m_errorState; // holds error state of Product Object

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Product(char type = 'N');
		Product(const char*, const char*, const char*, int qty = 0,
		bool taxable = true, double price = 0, int qtyNeeded = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
	};
	// helpers
	std::ostream& operator<<(std::ostream, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}
#endif // !AMA_PRODUCT_H

