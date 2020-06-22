// Ilias Halemi
// 062 111 133
// March 22, 2018
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		int m_attackBonus;
		int m_defend;

	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero&, const SuperHero&);
}
#endif