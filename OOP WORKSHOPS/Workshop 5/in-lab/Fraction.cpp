// Name: Ilias Halemi
// ID: 062 111 133
// Date: February 18,2018

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		m_numerator = 0;
		m_denominator = -1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator) {
		if (numerator >= 0 && denominator > 0) {
			m_numerator = numerator;
			m_denominator = denominator;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		return (m_numerator > m_denominator) ? m_numerator : m_denominator;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		return (m_numerator < m_denominator) ? m_numerator : m_denominator;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int a = gcd();

		m_numerator /= a;
		m_denominator /= a;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (m_denominator == 1) {
			cout << m_numerator;
		}
		else {
			cout << m_numerator << "/" << m_denominator;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		return (m_denominator == -1);
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction a;

		if (!isEmpty() && !rhs.isEmpty()) {
			a.m_numerator = (m_numerator * rhs.m_denominator) + (rhs.m_numerator * m_denominator);
			a.m_denominator = m_denominator * rhs.m_denominator;
			a.reduce();
		}

		return a;
	}
}