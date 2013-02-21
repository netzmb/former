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
		Part* part = getPartPrototype(partDirs->getFullFileName(fileIndex).c_str());
		_parts.push_back(part);
	}


	Logger::info("\t %d parts loaded", partDirs->getFileCount());

	if (partDirs)
		partDirs->drop();


	//
	// load materials list
	//

	Logger::info("\tloading materials");
	Json::Value matList;
	Parser::getJsonRoot("parts/materials.json", matList);

	matList = matList["materials"];

	for (Json::ArrayIndex i=0; i < matList.size(); i++) {

		std::string matName(matList[i]["name"].asString());

		// skip exist materials
		if (_materials.count(matName) > 0)
			continue;

		Logger::info("\t +material %s, density: %f\n", matName.c_str(), matList[i]["density"].asFloat());

		Material* material = new Material(matName);

		material->setDensity(matList[i]["density"].asFloat());

		_materials[matName] = material;
	}


	Logger::info("\t%d materials loaded", _materials.size());

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

	// TODO clear materials list on close in stuffmgr

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


Part* StuffManager::getPartPrototype(const std::string& config) {
	//Parser parser()

	// TODO add parts - wide part dynamic property adder

	// FIXME
	//return new Battery(config);

	Part* part = new Part(config.c_str());

	return part;
}
