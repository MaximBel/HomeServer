/*
 * SensorUnit.hpp
 *
 *  Created on: Feb 18, 2019
 *      Author: maksym.belei
 */

#ifndef SENSORUNIT_HPP_
#define SENSORUNIT_HPP_

#include <iostream>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <map>
#include <set>
#include <memory>

#include "DataUnit.hpp"

using std::string;
using std::pair;
using std::set;
using std::unique_ptr;
using std::shared_ptr;


enum: uint8_t{
	SENSOR_INFO_NAME = 0,
	SENSOR_INFO_DESCRIPTION
} SensorInfo;

using SensorInfoPair = pair<typeof(SensorInfo), string>;
using ListOfSensors = unique_ptr<set<uint32_t>>;

template<typename T> class SensorUnit: public DataUnit {

private:
	uint32_t sensorHash;
	SensorInfoPair sensorInfo;

	shared_ptr<set<T>> dataSetyPointer;

public:
	SensorUnit(uint32_t hash);
	virtual	~SensorUnit();

	void setSensorInfo(SensorInfoPair info);
	unique_ptr<SensorInfoPair>& getSensorInfo(SensorInfoPair info);

	void setDataSet(shared_ptr<set<T>> dataPtr);
	shared_ptr<set<T>> getDataSet(void);

	static ListOfSensors getListOfSensors(void);
};




#endif /* SENSORUNIT_HPP_ */
