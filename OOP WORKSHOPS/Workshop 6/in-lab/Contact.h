#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact {
		// Data
		char m_name[20];
		long long* m_phoneNumbers;
		int m_size;

	public:
		Contact();
		Contact(const char*, long long*, int);
		~Contact();

		bool isEmpty() const;
		void display() const;
	};
}

#endif