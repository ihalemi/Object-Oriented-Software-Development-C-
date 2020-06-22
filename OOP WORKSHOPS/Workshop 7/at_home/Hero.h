// Ilias Halemi
// 062 111 133
// March 19th, 2018
#ifndef SICT_HERO_H
#define SICT_HERO_H

#define max_rounds 100

namespace sict {
	class Hero {
		char m_name[41];
		int m_attack;
		int m_health;

	public:

		Hero();
		Hero(const char*, int, int);

		void operator-=(int);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& , const Hero& );

	};
	const Hero& operator*(const Hero&, const Hero&);
}
#endif
