/*
 * state_gameflow.h
 *
 *  Created on: 12 груд. 2012
 *      Author: moss
 */

#ifndef STATE_GAMEFLOW_H_
#define STATE_GAMEFLOW_H_

#include "state.h"

class GameflowState: public State {
public:
	bool init();
	void update();
	void close();
};

#endif /* STATE_GAMEFLOW_H_ */
