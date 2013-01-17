//
// part.h
//
//


#ifndef _PART_H_
#define _PART_H_

#include <irrlicht.h>
#include "material.h"

using irr::io::path;

class Part {
public:

protected:
	Part() : _configFile(), _mass(0), _hitPoints(0), _explosiveFactor(0) {};

private:

	// protect creating abstract part

	path _configFile;

	irr::core::list<Material> _materials;
	float _mass;
	int _hitPoints;
	int _explosiveFactor;
	irr::core::list<irr::core::stringc> _scripts;
};


#endif /* _PART_H_ */
