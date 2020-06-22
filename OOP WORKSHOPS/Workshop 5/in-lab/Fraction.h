// Name: Ilias Halemi
// ID: 062 111 133
// Date: February 18,2018

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H


// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int m_numerator;
		int m_denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int numerator, int denominator);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
	};
}
#endif // !SICT_FRACTION_H