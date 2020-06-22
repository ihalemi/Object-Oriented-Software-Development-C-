// Final Project Milestone 1
//
// Version 1.0
// Date: March 9th, 2018
// Author: Ilias Halemi
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {
	  // Error States
#define NO_ERROR 0   // No error - Date Valid   
#define CIN_FAILED 1 // istream failed on infromation entry
#define YEAR_ERROR 2 // Year value is invalid 
#define MON_ERROR 3  // Month value is invalid 
#define DAY_ERROR 4  // Day value is invalid

	  // Data Members
	  int m_year;
	  int m_month;
	  int m_day;
	  int m_compare;
	  int m_errorState;

     int mdays(int, int)const;
	 void errCode(int);
 
  public:
	  // Constructors
	  Date();
	  Date(int, int, int);

	  // Operators
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	  // Queries and Modifiers
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream&);
	  std::ostream& write(std::ostream&) const;
  };

  // Helper Functions
  std::ostream& operator<<(std::ostream& ostr, const Date& s);
  std::istream& operator>>(std::istream& istr, Date& s);

}
#endif