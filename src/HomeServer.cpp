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

	volatile auto data = new DataUnit(20);

	string str;

	data->loadData("debug", str);

	//data->removeDataUnit();

	cout << "!!!Hello World" << endl; // prints !!!Hello World!!!
	return 0;
}
