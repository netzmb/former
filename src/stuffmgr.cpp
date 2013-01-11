/*
 * stuffmgr.cpp
 *
 *  Created on: 20 груд. 2012
 *      Author: moss
 */

#include "stuffmgr.h"

#include "configuration.h"
#include "logger.h"

// jsoncpp lib
#include "json/json.h"

#include "parser.h"
#include "parts/battery.h"





bool StuffManager::init() {

	Logger::info("StuffManager::init()");

	_fileSystem = Config::instance().getFS();

	//
	// load parts
	//
	Logger::info("\tscanning game data for parts");
	IFileList* partDirs = getPartDirectories();


	Logger::info("\t loading parts");


	for(u32 fileIndex = 0; fileIndex < partDirs->getFileCount(); fileIndex++) {


		//Part* part = getPartPrototype(partDirs->getFullFileName(fileIndex));
		Part* part = getPartPrototype(partDirs->getFullFileName(fileIndex));
		_parts.push_back(part);
	}


	Logger::info("\t %d parts loaded", partDirs->getFileCount());

	if (partDirs)
		partDirs->drop();

	return true;
}



void StuffManager::update() {
	return;
}



void StuffManager::close() {
	Logger::info("StuffManager::close() begin");

	std::list<Part*>::iterator i=_parts.begin();
	while (i != _parts.end())
	{
		delete (*i);
		i =_parts.erase(i);
	}

	Logger::info("StuffManager::close() done");

	return;
}



irr::io::IFileList* StuffManager::getPartDirectories(const irr::io::path& dirPath) {

	Logger::info("\t part dirs scan, sources: %d", _fileSystem->getFileArchiveCount());

	IFileList* partDirs = _fileSystem->createEmptyFileList(_fileSystem->createFileList()->getPath(), true, false);

	for (irr::u32 archIndex=0; archIndex < _fileSystem->getFileArchiveCount(); ++archIndex) {

		Logger::info("\t file archive # %d", archIndex);

		// scan files

		const IFileList* files = _fileSystem->getFileArchive(archIndex)->getFileList();

		for (irr::u32 fileIndex=0; fileIndex < files->getFileCount(); ++fileIndex) {

			if (!files->getFileName(fileIndex).equals_ignore_case("part.json"))
				continue;

			//_fileSystem->getFileDir(files->getFullFileName(fileIndex))
			partDirs->addItem(files->getFullFileName(fileIndex),
					files->getFileOffset(fileIndex),
					files->getFileSize(fileIndex),
					false);


			Logger::info("\t arch[%d]\t part: %s",
					archIndex,
					files->getFullFileName(fileIndex).c_str());
		}
	}

	return partDirs;
}


Part* StuffManager::getPartPrototype(const path& config) {
	//Parser parser()


	// FIXME
	//return new Battery(config);
	return 0;
}
