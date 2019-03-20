/*
 * DataUnit.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: maksym.belei
 */

#include "DataUnit.hpp"

#include <iostream>
#include <fstream>

using std::fstream;
using std::ios;
using std::cout;
using std::endl;

DataUnit::DataUnit(uint32_t hash) {
	fstream file("test.txt",  ios::out);



	if(file.is_open()) {



	}

}
DataUnit::~DataUnit() {

}

bool DataUnit::loadData(string file, string& data) {

}
bool DataUnit::saveData(string file, string data) {

}

bool DataUnit::loadInfo(pair<uint8_t, string>& pair) {

}
bool DataUnit::saveInfo(pair<uint8_t, string> pair) {

}

//PRIVATE METHODS

bool DataUnit::prepareDataUnit() {

}


