// Ilias Halemi
// 062 111 133
// March 19th, 2018
#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;

namespace sict {

	Hero::Hero() {
		m_name[0] = '\0';
		m_health = 0;
		m_attack = 0;
	}

	Hero::Hero(const char* name, int health, int attack) {
		if (name != '\0' && health > 0 && attack > 0) {
			strcpy(m_name, name);
			m_health = health;
			m_attack = attack;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			m_health -= attack;
		}
		else {

		}
		
		if (m_health < 0) {
			m_health = 0;
		}
	}

	bool Hero::isAlive() const {
		return (m_health > 0);
	}

	int Hero::attackStrength() const {
		if (m_name[0] != '\0' && m_health != 0 && m_attack != 0) {
			return m_attack;
		}
		else {
			return 0;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.m_name[0] != '\0' && hero.m_health != 0 && hero.m_attack != 0) {
			os << hero.m_name;
			
		}
		else {
			cout << "No hero" << endl;
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {

		cout << "Ancient Battle! " << first << " vs " << second << " : ";

		// Make copies of each hero
		Hero A = first;
		Hero B = second;
		const Hero *winner = nullptr;

		int rounds = 0;

		while (A.isAlive() && B.isAlive() && rounds < max_rounds) {
			rounds++;
			A -= B.attackStrength();
			B -= A.attackStrength();
		}

		// In case both heroes alive after max_rounds
		bool isDraw = A.isAlive() && B.isAlive();

		if (isDraw) {
			winner = &first;
		}
		else if(A.isAlive()){
			winner = &first;
		}
		else {
			winner = &second;
		}

		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;
		
		return *winner;
	}

} // END OF NAMESPACE 
