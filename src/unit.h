//
// unit.cpp
//

#ifndef _UNIT_H_
#define _UNIT_H_


#include <list>

#include "player.h"
#include "instruction.h"
#include "part.h"


class Unit {
  Player _owner;
  //int _owner;
  bool _active;
  bool _selected;
  int _hitPoints;
  std::list <Instruction> _instructions;
  std::list <Part> _parts;
};

#endif /* _UNIT_H_ */

