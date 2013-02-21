/*
 * part.cpp
 *
 *  Created on: 20 лют. 2013
 *      Author: moss
 */


#include "part.h"
#include "parser.h"
#include "stuffmgr.h"
#include "logger.h"


Part::Part(const std::string& configFile) :
	_configFile(configFile),
	_mass(0),
	_hitPoints(0),
	_explosiveFactor(0) {

	Json::Value root;
	Parser::getJsonRoot(configFile, root);
	root = root["part"];

	_name	    = root["name"].asString();
	_className  = root["class"].asString();
	_model      = root["model"].asString();
	_mass	    = root["mass"].asFloat();
	_hitPoints  = root["hitPoints"].asInt();
	_durability = root["durability"].asInt();
	_explosiveFactor = root["explosive"].asInt();

	//
	// load materials
	//

	Json::Value::Members matNames = root["materials"].getMemberNames();

	for (Json::Value::Members::iterator i=matNames.begin(); i != matNames.end(); i++) {
		std::string matName = (*i);

		const Material* material = StuffManager::instance().getMaterial(matName);

		if (material == NULL) {
			Logger::warning("\t material does not exist: %s", matName.c_str());
			continue;
		}

		_materials[material] = root["materials"][matName.c_str()].asFloat();
	}




	return;
}



