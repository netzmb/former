//
// part.c
//
//


#ifndef _PART_H_
#define _PART_H_

#include <list>
#include <string>
#include "material.h"


class Part {
  private:
  std::list<Material> _materials;
  float _mass;
  int _hitPoints;
  int _explosiveFactor;
  std::list<std::string> _scripts;
};


#endif /* _PART_H_ */
