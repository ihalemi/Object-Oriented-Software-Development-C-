// Ilias Halemi
// 062 111 133
// March 22, 2018
#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;
using namespace sict;

namespace sict {
	SuperHero::SuperHero() {
		m_attackBonus = 0;
		m_defend = 0;
	}

	SuperHero::SuperHero(const char* name, int health, int attack, int attackBonus, int defend) : Hero(name, health, attack) {
		if (attackBonus != 0 && defend != 0) {
			m_attackBonus = attackBonus;
			m_defend = defend;
		}
		else {
			*this = SuperHero();
		}
	}

	int SuperHero::attackStrength() const {
		return (Hero::attackStrength() != -1) ? Hero::attackStrength() + m_attackBonus : 0;
	}

	int SuperHero::defend() const {
		return (m_defend != -1) ? m_defend : 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		cout << "Super Fight! " << first << " vs " << second << " : ";

		// Make copies of each hero
		SuperHero A = first;
		SuperHero B = second;
		const SuperHero *winner = nullptr;

		int rounds = 0;

		while (A.isAlive() && B.isAlive() && rounds < max_rounds) {
			rounds++;
			A -= B.attackStrength() - A.defend();
			B -= A.attackStrength() - B.defend();
		}

		// In case both heroes alive after max_rounds
		bool isDraw = A.isAlive() && B.isAlive();

		if (isDraw) {
			winner = &first;
		}
		else if (A.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}

		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

		return *winner;
	}

} // end of namespace sict
