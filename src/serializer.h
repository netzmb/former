/*
 * serializer.h
 *
 *  Created on: 13 груд. 2012
 *      Author: moss
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <irrlicht.h>

using namespace irr::scene;
using namespace irr::io;

class SceneSerializer : public ISceneUserDataSerializer {
public:
	SceneSerializer(ISceneManager* sceneMgr, path scenePath)
		: _sceneMgr(sceneMgr),
		  _scenePath(scenePath){};

	~SceneSerializer(){};
	void OnReadUserData(ISceneNode* forSceneNode, IAttributes* userData);
	void OnCreateNode(ISceneNode* node);
	IAttributes* createUserData(ISceneNode* forSceneNode);
private:
	ISceneManager* _sceneMgr;
	path _scenePath;
};

#endif /* SERIALIZER_H_ */
