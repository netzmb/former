//
// unit.cpp
//

#ifndef _UNIT_H_
#define _UNIT_H_


#include <irrlicht.h>

#include "player.h"
#include "instruction.h"
#include "part.h"


class Unit {
  Player _owner;
  //int _owner;
  bool _active;
  bool _selected;
  int _hitPoints;
  irr::core::list<Instruction> _instructions;
  irr::core::list<Part> _parts;
};

#endif /* _UNIT_H_ */

