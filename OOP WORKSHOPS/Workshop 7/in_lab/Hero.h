#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>
#define max_rounds 100

namespace sict {
	class Hero
	{
		char m_name[41];
		unsigned int m_health;
		unsigned int m_attack;
	public:
		Hero();
		Hero(const char*, int, int);

		void operator-=(int);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};
	const Hero& operator*(const Hero&, const Hero&);
}
#endif