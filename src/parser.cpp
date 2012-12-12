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
#include "parser.h"
#include "logger.h"
#include "configuration.h"


#include "states/splash_image.h"

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



Json::Value Parser::getJsonRoot(const stringc& jsonFile) {

	Json::Value root;

	// TODO implement read json from archived resources
	std::string resName("data/");
	resName.append(jsonFile.c_str());
	std::ifstream resFile;
	resFile.open(resName.c_str(), std::ios::out);

	if (!resFile.is_open()) {
		Logger::warning("res file does not open: %s", jsonFile.c_str());
		return root;
	}

	std::ostringstream fileStream;

	fileStream << resFile.rdbuf();

	std::string resStrData(fileStream.str().c_str());
	//std::cout << resStrData << std::endl;


	Json::Reader reader;

	if (!reader.parse(resStrData, root)) {
		Logger::warning("failed to parse %s : %s",
				jsonFile.c_str(),
				reader.getFormatedErrorMessages().c_str());

		return root;
	}

	return root;
}




bool Parser::parseStates(StateManager* stManager) {
	Logger::info("StateManager parse states");

	Json::Value root = getJsonRoot("init.json");

	const Json::Value states = root["states"];

	for(uint i=0; i < states.size(); ++i) {
		stringc stateName = states[i]["type"].asCString();
		Logger::info("Parser() add state: %s", stateName.c_str());



		//
		// process splash image state
		//
		if (stateName.equals_ignore_case("splash_image")) {
			SplashImageState* state = static_cast<SplashImageState*>(
					stManager->addState(StateManager::STATE_TYPE_SPLASH_IMAGE));

			// TODO new common init(<some dict>) method for all derived "State"

			state->setImagePath(states[i]["file"].asCString());
			state->setAudioPath(states[i]["audio"].asCString());
			state->setTimeout(states[i]["timeout"].asUInt());
			state->setBackColor(parseColor(states[i]["color"]));


			Logger::info("\tfile: %s audio: %s timeout: %d",
					states[i]["file"].asCString(),
					states[i]["audio"].asCString(),
					states[i]["timeout"].asUInt());

			state->init();
		}
	}

	Logger::info("StateManager parse states end");
	return true;
}


irr::video::SColor Parser::parseColor(const Json::Value& root) {
	irr::video::SColor color;

	color.set(root[0].asUInt(),	// a
			  root[1].asUInt(),	// r
			  root[2].asUInt(), // g
			  root[3].asUInt());// b

	return color;
}

