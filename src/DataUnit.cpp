/*
 * DataUnit.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: maksym.belei
 */

#include "DataUnit.hpp"

#include <iostream>
#include <fstream>
#include <dirent.h>
#include "Utils.hpp"
#include <cstring>
#include <stdio.h>

using namespace std;

using std::fstream;
using std::ios;
using std::cout;
using std::endl;
using std::to_string;


const string DataUnit::DATA_FOLDER = "Data/";

 const string DataUnit::INFO_FILE = "INFO.txt";

DataUnit::DataUnit(uint32_t hash):
	unitPath(DATA_FOLDER + to_string(hash) + "/"){

	DIR* dir = opendir(unitPath.c_str());

	if(dir == nullptr) {
		prepareDataUnit();
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

unique_ptr<set<uint32_t>> DataUnit::getDataUnitList(void) {
	unique_ptr<set<uint32_t>> unitPtr(new set<uint32_t>);

	    DIR *dir = opendir(DATA_FOLDER.c_str());

	    if(dir == nullptr) {
	    	return unitPtr;
	    }

	    struct dirent *entry = readdir(dir);

	    while (entry != NULL) {
	        if (entry->d_type == DT_DIR) {
	        	if(!strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
	        		unitPtr.get()->emplace(atoi(entry->d_name));
	        	}
	        	 printf("Folder in data: %s\n", entry->d_name);
	        }
	        entry = readdir(dir);
	    }

	    closedir(dir);

	    return unitPtr;
}

//PRIVATE METHODS

bool DataUnit::prepareDataUnit() {
	fstream file(unitPath + INFO_FILE,  ios::out);

	file.close();
}





