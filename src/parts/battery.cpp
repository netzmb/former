/*
 * battery.cpp
 *
 *  Created on: 11 січ. 2013
 *      Author: moss
 */

#include "battery.h"

Battery::Battery(const path& config)
	: _configFile(config),
	  _capacity(0),
	  _mass(0),
	  _hitPoints(0),
	  _explosiveFactor(0) {

	return;
}



