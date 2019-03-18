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

struct {
	string unitName;
	string unitDescription;
	uint32_t* dataPointer;
	uint32_t dataSize;
} dataUnitInfo;

class DataUnit {

public:

	DataUnit();
	virtual ~DataUnit();

	void setDataUnitInfo(struct dataUnitInfo unitInfo);

	bool loadData();

	bool saveData();

private:

	struct dataUnitInfo unitInfo;

	bool prepareDataUnit();

};



#endif /* DATAUNIT_HPP_ */
