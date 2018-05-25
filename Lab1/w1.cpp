#include "Process.h"
#include "CString.h"
#include <iostream>

using namespace w1;
using namespace std;

int main(int argc, char* argv[]) {
	cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;
	
	if (argc <= 1) {
		cout << "Insufficient number of arguments (min 1)" << endl;
		return 1; // return that program was unsuccessful
	}

	cout << "Maximum number of characters stored : " << MAX_CHAR << endl;

	for (int i = 1; i < argc; i++) {
		process(argv[i]);
	}

	return 0;
} // end of main