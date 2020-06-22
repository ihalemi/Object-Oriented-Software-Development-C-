// TODO: add file header comments here
// Name: Ilias Halemi
// Date: 02/12/2018
// Student ID: 062 111 133

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_year = 0;
		m_month = 0;
		m_day = 0;
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == nullptr || destination == nullptr) {
			*this = Passenger();
		}
		else {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
			m_year = 2017;
			m_month = 07;
			m_day = 01;
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		
		bool empty = (m_name[0] == '\0' || m_destination[0] == '\0');
		return empty;
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (m_name[0] == '\0' || m_destination == '\0')
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << m_name << " - " << m_destination << " on " << m_year << "/" <<
				setfill('0') << setw(2) << m_month << "/" << setfill('0') << setw(2)<< m_day << endl;
		}
	}

	// At-Home
	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) {
		// valid passenger data
		if (name != nullptr && destination != nullptr && name[0] != '\0' && destination[0] != '\0'
			&& year >= 2017 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
			m_year = year;
			m_month = month;
			m_day = day;
		}
		else {
			*this = Passenger();
		}
	}

	const char* Passenger::name() const {
		if (isEmpty() == false) {
			return m_name;
		}
		else {
			return '\0';
		}
	}

	bool Passenger::canTravelWith(const Passenger& a) const {
		if (strcmp(m_destination, a.m_destination) == 0 && m_year == a.m_year &&
			m_month == a.m_month && m_day == a.m_day) {
			return true;
		}
		else {
			return false;
		}
	}
}
