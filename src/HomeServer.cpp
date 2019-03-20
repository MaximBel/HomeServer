//============================================================================
// Name        : HomeServer.cpp
// Author      : Maksym Belei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "DataUnit.hpp"


int main() {

	volatile auto data = new DataUnit(10);

	cout << "!!!Hello World" << endl; // prints !!!Hello World!!!
	return 0;
}
