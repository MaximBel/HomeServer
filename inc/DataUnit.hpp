/*
 * DataUnit.hpp
 *
 *  Created on: Mar 18, 2019
 *      Author: maksym.belei
 */

#ifndef DATAUNIT_HPP_
#define DATAUNIT_HPP_

#include <iostream>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <map>
#include <memory>
#include <set>

using std::string;
using std::pair;
using namespace std;


class DataUnit {

public:

	DataUnit(uint32_t hash);
	virtual ~DataUnit();

	bool loadData(string file, string& data);
	bool addData(string file, string data);
	bool clearData(string file, bool withFile);

	bool loadInfo(pair<uint8_t, string>& pair);
	bool saveInfo(pair<uint8_t, string> pair);

	void removeDataUnit();

	unique_ptr<set<uint32_t>> getDataUnitList(void);

private:

	static const string DATA_FOLDER;

	static const string INFO_FILE;

	const string unitPath;

	bool prepareDataUnit();

	bool removeDirectoryFR(const char *dirname);

};



#endif /* DATAUNIT_HPP_ */
