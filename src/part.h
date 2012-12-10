//
// part.c
//
//


#ifndef _PART_H_
#define _PART_H_

#include <irrlicht.h>
#include "material.h"


class Part {
  private:
  irr::core::list<Material> _materials;
  float _mass;
  int _hitPoints;
  int _explosiveFactor;
  irr::core::list<irr::core::stringc> _scripts;
};


#endif /* _PART_H_ */
