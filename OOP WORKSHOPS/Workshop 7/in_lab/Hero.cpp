#include <iostream>
#include <iomanip>
#include "Hero.h"

using namespace std;

namespace sict {
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_health = 0;
		m_attack = 0;
	}

	Hero::Hero(const char* name, int health, int attack)
	{
		if (name[0] != '\0' && health > 0 && attack > 0) {
			strncpy(m_name, name, 41);
			m_health = health;
			m_attack = attack;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack)
	{
		if (attack > 0 && m_health > 0) {
			m_health -= attack;
		}

		if (m_health < 0) {
			m_health = 0;
		}
	}

	bool Hero::isAlive() const
	{
		return (m_health > 0);
	}

	int Hero::attackStrength() const
	{
		if (m_name[0] != '\0' && m_health != 0 && m_attack != 0) {
			return m_attack;
		}
		else {
			return 0;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.m_name[0] != '\0' && hero.m_health != 0 && hero.m_attack != 0) {
			os << hero.m_name;
		}
		else {
			cout << "No hero" << endl;
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second)
	{
		cout << "Ancient Battle! " << first << " vs " << second << " : ";

		// make copies of each hero
		Hero a = first;
		Hero b = second;
		// pointer to the winner object
		const Hero *winner = nullptr;

		int round = 0;

		for (int i = 0; i < max_rounds && (a.isAlive() && b.isAlive()); ++i)
		{
			a -= b.attackStrength();
			b -= a.attackStrength();
			round = i;
		}

		round++;

		// in case both alive after 100 rounds have passed
		bool isDraw = (a.isAlive() && b.isAlive());

		// determine the winner if there is a draw
		if (isDraw) {
			winner = &first;
		}
		else if (a.isAlive()) {
			winner = &first;
		}
		else {
			winner = &second;
		}

		cout << "Winner is " << *winner << " in " << round << " rounds." << endl;
		return *winner;
	}

} // END OF NAMESPACE