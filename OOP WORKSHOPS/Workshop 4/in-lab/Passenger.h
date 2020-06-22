// TODO: add file header comments here
// Name: Ilias Halemi
// Date: 02/12/2018
// Student ID: 062 111 133

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		char m_name[32];
		char m_destination[32];

	public:
		Passenger();
		Passenger(const char* name, const char* destination);

		bool isEmpty() const;
		void display() const;
	};
}
#endif
