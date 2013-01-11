/*
 * stuffmgr.h
 *
 *  Created on: 20 груд. 2012
 *      Author: moss
 */

#ifndef STUFFMGR_H_
#define STUFFMGR_H_


#include <list>
#include <string>

#include <irrlicht.h>


#include "singleton.h"
#include "part.h"



using irr::io::path;
using irr::io::IFileList;
using irr::u32;



class StuffManager : public Singleton<StuffManager> {
public:
	bool init();
	void update();
	void close();

private:

	Part* getPartPrototype(const path &config);

	IFileList* getPartDirectories(const path& dirPath = path());

	std::list<Part*> _parts;



	irr::io::IFileSystem* _fileSystem;
};

#endif /* STUFFMGR_H_ */
