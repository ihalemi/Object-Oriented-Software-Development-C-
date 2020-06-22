// Ilias Halemi
// 062 111 133
// March 22, 2018

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Product.h"

using namespace std;

namespace AMA {
	// protected member functions
	void Product::name(const char* pName) {
		if (pName == nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
		
		m_name = new char[strlen(pName) + 1];
		strncpy(m_name, pName, strlen(pName) + 1);
	}

	const char* Product::name() const {
		if (m_name != nullptr) {
			return m_name;
		}
		else {
			return nullptr;
		}
	}

	const char* Product::sku() const {
		return m_sku;
	}

	const char* Product::unit() const {
		return m_unit;
	}

	bool Product::taxed() const {
		return m_taxable;
	}

	double Product::price() const {
		return m_price;
	}

	double Product::cost() const {
		if (m_taxable) {
			return m_price + (m_price * tax_rate);
		}
		else {
			return m_price;
		}
	}

	void Product::message(const char* error) {
		m_errorState.message(error);
	}

	bool Product::isClear() const {
		return m_errorState.isClear();
	}

	// public member functions
	Product::Product(char type) {
		m_type = type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_price = 0.0;
		m_taxable = true;
	}

	Product::Product(const char* sku, const char* pName, const char* unit, int qty,
	bool taxable, double price, int qtyNeeded) {
		strncpy(m_sku, sku, max_sku_length);
		m_name = nullptr;
		name(pName);
		strncpy(m_unit, unit, max_unit_length);
		m_qty = qty;
		m_taxable = taxable;
		m_price = price;
		m_qtyNeeded = qtyNeeded;
		m_errorState.clear();
	}

	Product::Product(const Product& a) {
		m_name = nullptr;
		*this = a;
	}

	Product& Product::operator=(const Product& a) {
		if (this != &a) {
			m_type = a.m_type;
			strncpy(m_sku, a.m_sku, max_sku_length);
			strncpy(m_unit, a.m_unit, max_unit_length);
			m_name = nullptr;
			name(a.m_name);
			m_qty = a.m_qty;
			m_qtyNeeded = a.m_qtyNeeded;
			m_price = a.m_price;
			m_taxable = a.m_taxable;

			if (!a.isClear()) {
				m_errorState.message(a.m_errorState.message());
			}
		}
		return *this;
	}

	Product::~Product() {
		delete[] m_name;
		m_name = nullptr;
		m_errorState.clear();
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		if (file.is_open()) {
			file << m_type << ',' << m_sku << ',' << m_name << ',' << m_unit <<
				',' << m_taxable << ',' << m_price << ',' << m_qty << ',' << m_qtyNeeded;
		}

		if (newLine) {
			file << endl;
		}
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		char sku[max_sku_length + 1];
		char* name;
		char unit[max_unit_length + 1];
		int qty;
		int qtyNeed;
		double price;
		bool taxable;
		name = new char[max_name_length + 1];

		if (file.is_open())
		{
			file.getline(sku, max_sku_length + 1, ',');
			file.getline(name, max_name_length + 1, ',');
			file.getline(unit, max_unit_length + 1, ',');
			
			file >> taxable;
			file.ignore();
			file >> price;
			file.ignore();
			file >> qty;
			file.ignore();
			file >> qtyNeed;

			Product temp(sku, name, unit, qty, taxable, price, qtyNeed);
			*this = temp;
		}

		delete[] name;
		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		
		if (!m_errorState.isClear()) { // added for MS5
			os << m_errorState.message();
		}
		else if (linear) {
			os << left << setw(max_sku_length) << setfill (' ') << m_sku << '|'
				<< left << setw(20) << setfill(' ') << m_name << '|'
				<< fixed << setprecision(2) << right << setw(7) << setfill(' ') << cost() << '|'
				<< right << setw(4) << setfill(' ') << m_qty << '|'
				<< left << setw(10) << setfill(' ') << m_unit << '|'
				<< right << setw(4) << m_qtyNeeded << '|';
		}
		else {
			os << " Sku: " << m_sku << endl;
			os << " Name (no spaces): " << m_name << endl;
			os << " Price: " << m_price << endl;

			if (m_taxable) {
				os << " Price after tax: " << cost() << endl;
			}
			else {
				os << " Price after tax: N/A" << endl;
			}
			os << " Quantity on Hand: " << m_qty << " " << m_unit << endl;
			os << " Quantity needed: " << m_qtyNeeded;
		}
		return os;
	}

	std::istream & Product::read(std::istream& is) { 
		m_errorState.clear();
		char sku[max_sku_length + 1];
		char* pName;
		char unit[max_unit_length + 1];
		char taxed;
		double price;
		int qty;
		int qtyNeeded;

		// allocate memory
		pName = nullptr;
		pName = new char[max_name_length + 1];
		
			cout << " Sku: ";
			is >> sku;
			cout << " Name (no spaces): ";
			is >> pName;
			cout << " Unit: ";
			is >> unit;

			cout << " Taxed? (y/n): ";
			is >> taxed;
			if (taxed != 'y' && taxed != 'n' && taxed != 'Y' && taxed != 'N') {
				is.setstate(ios::failbit);
				m_errorState.message("Only (Y)es or (N)o are acceptable");
				return is;
			}

			cout << " Price: ";
			is >> price;
			if (is.fail()) {
				m_errorState.message("Invalid Price Entry");
				is.setstate(ios::failbit);
				return is;
			}

			cout << " Quantity on hand: ";
			is >> qty;
			if (is.fail()) {
				m_errorState.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}

			cout << " Quantity needed: ";
			is >> qtyNeeded;
			cin.ignore();

			if (is.fail()) {
				m_errorState.message("Invalid Quantity Needed Entry");
				return is;
			}

			if (m_errorState.isClear()) {
				bool isTaxed;

				if (taxed == 'y' || taxed == 'Y') {
					isTaxed = true;
				}
				else {
					isTaxed = false;
				}

				strncpy(m_sku, sku, max_sku_length);
				m_name = nullptr;
				name(pName);
				strncpy(m_unit, unit, max_unit_length);
				quantity(qty);
				m_qtyNeeded = qtyNeeded;
				m_price = price;
				m_taxable = isTaxed;
			}
			// clean up memory
			delete[] pName;
			return is;
	}

	bool Product::operator==(const char* str) const {
		return (str == m_sku);
	}

	double Product::total_cost() const {
		return (m_qty * cost());
	}

	void Product::quantity(int units) {
		m_qty = units;
	}

	bool Product::isEmpty() const {
		return (m_name == nullptr);
	}

	int Product::qtyNeeded() const {
		return m_qtyNeeded;
	}

	int Product::quantity() const {
		return m_qty;
	}

	bool Product::operator>(const char* sku) const {
		int a = strcmp(m_sku, sku);
		return (a > 0);
	}

	bool Product::operator>(const iProduct& a) const {
		int b = strcmp(m_sku, a.name());
		return (b > 0);
	}

	int Product::operator+=(int units) {
		if (units > 0) {
			m_qty += units;
			return m_qty;
		}
		else {
			return m_qty;
		}
	}

	// helpers
	std::ostream& operator<<(std::ostream& os, const iProduct& a) {
		return a.write(os, true);
	}

	std::istream& operator>>(std::istream& is, iProduct& a) {
		return a.read(is);
	}

	double operator+=(double& cost, const iProduct& a) {
		return cost += a.total_cost();
	}
	
} // end of namespace AMA