//
// instruction.h
//
//



#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_


class Instruction {
  public:
  virtual bool execute()=0;
  virtual ~Instruction();
};

#endif /* INSTRUCTION_H_ */ 

