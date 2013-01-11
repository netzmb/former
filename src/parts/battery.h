//
// battery.h
//
//

#include "../part.h"

#include <irrlicht.h>

using irr::io::path;

class Battery : public Part {
public:
	Battery(const path& config);
private:
	path configFile;

	float _capacity;

};


