/*
 * parser.h
 *
 *  Created on: 7 груд. 2012
 *      Author: moss
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <irrlicht.h>
#include <string>
#include <json/json.h>
#include "statemgr.h"

using irr::core::list;
using irr::core::stringc;

class Parser {
public:
	Parser();
	void parse(){};

	static bool parseStates(StateManager* stManager);

	static void getJsonRoot(const std::string& jsonFile, Json::Value& root);
	static irr::video::SColor parseColor(const Json::Value& root);


//private:
//	logError(const Json::Reader& reader, const std::string& resName);
};


#endif /* PARSER_H_ */
