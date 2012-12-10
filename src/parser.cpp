/*
 * parser.cpp
 *
 *  Created on: 7 груд. 2012
 *      Author: moss
 */



#include <irrlicht.h>
#include <string> // STL string
#include <fstream>
#include <sstream>
#include <json/json.h>
#include "parser.h"
#include "logger.h"
#include "configuration.h"


#include <iostream>

Parser::Parser() {

	// load states test
	//std::string resName("data/autoexec.json");

	//
	// reading file
	//

	// TODO implement read json from archived resources
	std::string resName("data/autoexec.json");
	std::ifstream resFile;
	resFile.open(resName.c_str(), std::ios::out);
	if (!resFile.is_open()) {
		Logger::warning("res file does not open: %s", resName.c_str());
		return;
	}

	std::ostringstream fileStream;

	fileStream << resFile.rdbuf();

	std::string resStrData(fileStream.str().c_str());

	std::cout << resStrData << std::endl;

	Json::Value root;
	Json::Reader reader;

	if (!reader.parse(resStrData, root)) {
		Logger::warning("failed to parse %s : %s",
				"blah.json",
				reader.getFormatedErrorMessages().c_str());

		return;
	}

	//
	// parsing
	//

	const Json::Value states = root["states"];

	for(uint i=0; i < states.size(); ++i) {
		Logger::info(states[i]["type"].asCString());
	}





	return;
}

