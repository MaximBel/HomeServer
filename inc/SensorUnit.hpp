/*
 * SensorUnit.hpp
 *
 *  Created on: Feb 18, 2019
 *      Author: maksym.belei
 */

#ifndef SENSORUNIT_HPP_
#define SENSORUNIT_HPP_

#include <iostream>
#include "stddef.h"
#include "stdint.h"
#include "string.h"
#include <set>

using std::string;
using std::set;

class DataUnit {
protected:
	uint32_t sensorHash;
	string sensorDescription;

public:
	DataUnit();
	virtual	~DataUnit();
	void setSensorHash(uint32_t hash);
	void setSensorDescription(string description);
	uint8_t build();

	set<uint32_t> getListOfSensors(void);
};




#endif /* SENSORUNIT_HPP_ */
