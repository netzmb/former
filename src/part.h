//
// part.h
//
//


#ifndef _PART_H_
#define _PART_H_

//#include <irrlicht.h>
#include "material.h"

#include <string>
#include <map>
#include <list>




class Part {
public:

	Part(const std::string& configFile);

private:

	// protect creating abstract part

	std::string _configFile;
	std::string _name;
	std::string _className;
	std::string _model;


	float _mass;
	int _hitPoints;
	int _durability;      // if _hitPoints < _durability, part set as broken
	int _explosiveFactor; // if _hitPoints < 0 and < _explosiveFactor, part explode

	std::map<const Material*, float> _materials;
	std::list<std::string> _scripts;
};


#endif /* _PART_H_ */
