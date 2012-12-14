/*
 * stage.h
 *
 *  Created on: 13 груд. 2012
 *      Author: moss
 */

#ifndef STAGE_H_
#define STAGE_H_

#include <irrlicht.h>

using irr::scene::ISceneManager;
using irr::scene::ISceneNode;
using irr::core::stringc;

class Stage {
public:
	Stage(const irr::core::stringc& stageName);
	~Stage();

	ISceneManager* getSceneManager() {return _sceneMgr;}

	// TODO fix stage saving name and path
	void dumpStage() {_sceneMgr->saveScene(_stageName + ".stagedump.irr");}
	void setAsMainStage();

private:
	ISceneManager* _sceneMgr;	// local scene manager
	irr::io::IFileSystem* _fileSystem;
	stringc _stageName;
};

#endif /* STAGE_H_ */
