// TODO: add file header comments here
// Name: Ilias Halemi
// Date: 02/12/2018
// Student ID: 062 111 133

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == nullptr || destination == nullptr) {
			*this = Passenger();
		}
		else {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool valid = (strlen(m_name) > 0 && strlen(m_destination) > 0);
	
		return !valid;
	}
	// TODO: implement display query here
	void Passenger::display() const {
		// * If either name or dest is empty
		if (m_name[0] == '\0' || m_destination == '\0')
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << m_name << " - " << m_destination << endl;
		}
	}
}
