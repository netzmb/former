/*
 * stagemgr.h
 *
 *  Created on: 13 груд. 2012
 *      Author: moss
 */

#ifndef STAGEMGR_H_
#define STAGEMGR_H_

#include "singleton.h"
#include "stage.h"
#include <irrlicht.h>



using irr::scene::ISceneManager;
using irr::core::stringc;
using irr::core::list;

class StageManager: public Singleton<StageManager> {
public:

	bool init();
	void update();
	void close();


	ISceneManager* getSceneManager() { return _irrSceneManager; }



	Stage* createStage(const stringc& stageName);
	//Stage* setMainStage(const stringc& stageName);
	Stage* setMainStage(Stage* stage) {_mainStage = stage; return _mainStage; }


private:

	ISceneManager* _irrSceneManager; // default system scene manager
	Stage* _mainStage;
	list<Stage*> _stages;

};

#endif /* STAGEMGR_H_ */
