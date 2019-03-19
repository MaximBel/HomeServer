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
#include <string.h>
#include <map>

using std::string;
using std::pair;

class DataUnit {

public:

	DataUnit(uint32_t hash);
	virtual ~DataUnit();

	bool loadData(string file, string& data);
	bool saveData(string file, string data);

	bool loadInfo(pair<uint8_t, string>& pair);
	bool saveInfo(pair<uint8_t, string> pair);

private:

	bool prepareDataUnit();

};



#endif /* DATAUNIT_HPP_ */
