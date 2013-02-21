//
// material.h
//
//


#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <irrlicht.h>
#include <string>

class Material {
public:
	Material(const std::string& name) :
		_name(name),
		_density(0) {};

	void setDensity(float density) { _density = density; }
	float getDensity() const { return _density; }

private:
  std::string _name;
  float _density;
};


#endif /* _MATERIAL_H_ */
