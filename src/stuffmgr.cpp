/*
 * stuffmgr.cpp
 *
 *  Created on: 20 груд. 2012
 *      Author: moss
 */

#include "stuffmgr.h"

#include "configuration.h"
#include "logger.h"



bool StuffManager::init() {

	Logger::info("StuffManager::init()");

	_fileSystem = Config::instance().getFS();

	//
	// load parts
	//
	IFileList* partDirs = getPartDirectories();


	if (partDirs)
		partDirs->drop();



	//_parts.push_back();

	return true;
}



void StuffManager::update() {
	return;
}



void StuffManager::close() {
	return;
}



irr::io::IFileList* StuffManager::getPartDirectories(const irr::io::path& dirPath) {

	Logger::info("\t part dirs scan, sources: %d", _fileSystem->getFileArchiveCount());

	IFileList* partDirs = NULL;

	for (irr::u32 archIndex=0; archIndex < _fileSystem->getFileArchiveCount(); ++archIndex) {

		Logger::info("\t file archive # %d", archIndex);

		// scan files

		const IFileList* files = _fileSystem->getFileArchive(archIndex)->getFileList();

		for (irr::u32 fileIndex=0; fileIndex < files->getFileCount(); ++fileIndex) {

			if (path("part.json") != files->getFileName(fileIndex))
				continue;

			Logger::info("\t arch[%d]\t part: %s",
					archIndex,
					files->getFullFileName(fileIndex).c_str());
		}
	}

	return partDirs;
}
