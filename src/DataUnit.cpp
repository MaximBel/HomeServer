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
#include <sys/stat.h>

using namespace std;

using std::fstream;
using std::ios;
using std::cout;
using std::endl;
using std::to_string;


const string DataUnit::DATA_FOLDER = "Data/";

 const string DataUnit::INFO_FILE = "INFO.txt";

DataUnit::DataUnit(uint32_t hash):
	unitPath(DATA_FOLDER + to_string(hash)){

	DIR* dir = opendir(unitPath.c_str());

	while(dir == nullptr) {
		prepareDataUnit();
		dir = opendir(unitPath.c_str());
	}

	closedir(dir);

}
DataUnit::~DataUnit() {

}

bool DataUnit::loadData(string file, string& data) {
	ifstream fileStream(unitPath + "/" + file);

	if(fileStream.is_open()) {
		data.assign(std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>());
		printf("string is next: %s", data.c_str());

		fileStream.close();

		return true;
	}

	return false;
}

bool DataUnit::addData(string file, string data) {

}

bool DataUnit::clearData(string file, bool withFile) {

}

bool DataUnit::loadInfo(pair<uint8_t, string>& pair) {

}

bool DataUnit::saveInfo(pair<uint8_t, string> pair) {

}



void DataUnit::removeDataUnit() {
	while(removeDirectoryFR(unitPath.c_str()) != true) {
		//do nothing. just deleting,
	}
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

	if(opendir(unitPath.c_str()) == nullptr) {
		// TODO: check this
		if(mkdir(unitPath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO) != 0) {
			return false;
		}
	}

	ofstream file(unitPath + "/" + INFO_FILE);

	file.close();
}

bool DataUnit::removeDirectoryFR(const char *dirname) {

    DIR *dir;
    struct dirent *entry;
    char path[PATH_MAX];

    if (path == NULL) {
        fprintf(stderr, "Out of memory error\n");
        return false;
    }
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opendir()");
        return false;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
        	snprintf(path, (size_t) PATH_MAX, "%s/%s", dirname, entry->d_name);

            if (entry->d_type == DT_DIR) {
            	if(false == removeDirectoryFR(path)) {
            		return false;
            	}
            } else {
                if(remove(path) != 0) {
                	printf("Deleting error: %d", errno);
                }
            }
        }

    }
    closedir(dir);

    /*
     * Now the directory is empty, finally delete the directory itself.
     */
    if(remove(path) != 0) {
    	printf("Deleting error. path: %s, errno: %d\n", path, static_cast<int>(errno));
    }

    return true;
}




