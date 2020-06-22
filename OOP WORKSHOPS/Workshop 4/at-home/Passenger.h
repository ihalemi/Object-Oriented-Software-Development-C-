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

		// At-Home
		int m_year;
		int m_month;
		int m_day;

	public:
		Passenger();
		Passenger(const char* name, const char* destination);
		bool isEmpty() const;
		void display() const;

		// At-Home
		Passenger(const char* name, const char* destination, int year, int month, int day);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif
