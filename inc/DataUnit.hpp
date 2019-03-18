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

using std::string;

class DataUnit {

public:

	DataUnit(uint32_t hash);
	virtual ~DataUnit();

	bool loadData(string file, string& data);

	bool saveData(string file, string data);

private:

	bool prepareDataUnit();

};



#endif /* DATAUNIT_HPP_ */
