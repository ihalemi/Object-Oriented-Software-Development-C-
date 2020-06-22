/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 1/30/2018
// Author Ilias Halemi
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(const Kingdom& pKingdom) {
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}

	void display(const Kingdom pKingdoms[], int size) {
		int total = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < size; i++) {
			cout << i + 1 << "."; 
			sict::display(pKingdoms[i]);

			total += pKingdoms[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;

	}
}