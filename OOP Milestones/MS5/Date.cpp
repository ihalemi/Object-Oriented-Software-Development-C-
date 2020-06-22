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
#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

  void Date::errCode(int errCode) {
	  m_errorState = errCode;
  }

  // Constructors
  Date::Date() {
	  m_year = 0000;
	  m_month = 00;
	  m_day = 00;
	  m_compare = 0;
	  m_errorState = NO_ERROR;
  }
 	
  Date::Date(int year, int month, int day) {

	  m_year = year;
	  m_month = month;
	  m_day = day;
	  m_errorState = NO_ERROR;
	  m_compare = (year * 372) + (month * 13) + day;
	  
	  if (year > max_year || year < min_year) {
		  *this = Date();
		  errCode(YEAR_ERROR);
	  }
	  else if (month > 12 || month < 1) {
		  *this = Date();
		  errCode(MON_ERROR);
	  }
	  else if (day > mdays(month, year) || day < 1) {
		  *this = Date();
		  errCode(DAY_ERROR);
	  }
	  else {
		  errCode(NO_ERROR);
	  }
	 
	  if (bad()) {
		  *this = Date();
	  }
  }

  // Operators
  bool Date::operator==(const Date& rhs) const {
	  return (m_compare == rhs.m_compare);
  }

  bool Date::operator!=(const Date& rhs) const {
	  return (m_compare != rhs.m_compare);
  }

  bool Date::operator<(const Date& rhs) const {
	  return (m_compare < rhs.m_compare);
  }

  bool Date::operator>(const Date& rhs) const {
	  return (m_compare > rhs.m_compare);
  }

  bool Date::operator<=(const Date& rhs) const {
	  return (m_compare <= rhs.m_compare);
  }

  bool Date::operator>=(const Date& rhs) const {
	  return (m_compare >= rhs.m_compare);
  }

  // Queries and Modifiers
  int Date::errCode() const {
	  return m_errorState;
  }

  bool Date::bad() const {
	  return (m_errorState != NO_ERROR);
  }

  std::istream& Date::read(std::istream& istr) {

	  istr >> m_year;
	  if (istr.get() != '/') {
		  errCode(CIN_FAILED);
		  return istr;
	  }

	  istr >> m_month;
	  if (istr.get() != '/') {
		  errCode(CIN_FAILED);
		  return istr;
	  }

	  istr >> m_day;

	  if (m_year > max_year || m_year < min_year) {
		  *this = Date();
		  errCode(YEAR_ERROR);
	  }
	  else if (m_month > 12 || m_month < 1) {
		  *this = Date();
		  errCode(MON_ERROR);
	  }
	  else if (m_day > mdays(m_month, m_year) || m_day < 1) {
		  *this = Date();
		  errCode(DAY_ERROR);
	  }
	  else {
		  errCode(NO_ERROR);

	  }

	  return istr;
  }

  std::ostream& Date::write(std::ostream& ostr) const {
	  ostr << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) << setfill('0') << m_day;

	  return ostr;
  }

  // Helper Functions
  std::ostream& operator<<(std::ostream& ostr, const Date& s) {
	  return s.write(ostr);
  }

  std::istream& operator>>(std::istream& istr, Date& s) {
	  return s.read(istr);
  }

} // END OF NAMESPACE
