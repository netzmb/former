/*
 * serializer.cpp
 *
 *  Created on: 13 груд. 2012
 *      Author: moss
 */

#include "serializer.h"

#include "stagemgr.h"
#include "configuration.h"
#include "logger.h"



void SceneSerializer::OnReadUserData(ISceneNode* forSceneNode, IAttributes* userData) {
	irr::io::IFileSystem* fileSystem = Config::instance().getFS();
	irr::io::IAttributes* attribs = fileSystem->createEmptyAttributes(Config::instance().getIrrDevice()->getVideoDriver());
	forSceneNode->serializeAttributes(attribs);

	Logger::info("OnReadUserData Node name: %s", forSceneNode->getName());

	if (forSceneNode->getType() != irr::scene::ESNT_MESH) {
		Logger::info("\tOnReadUserData Mesh: NOT MESH: %d", forSceneNode->getType());
		Logger::info("\tOnReadUserData mesh name: %s", attribs->getAttributeAsString("Mesh").c_str());
		attribs->drop();
		return;
	} else {
		Logger::info("\tOnReadUserData is Mesh: %s", forSceneNode->getName());
	}

	if (!attribs->existsAttribute("Mesh")) {
		Logger::info("\tOnReadUserData Mesh: NOT FOUND");
		attribs->drop();
		return;
	}

	Logger::info("\tOnReadUserData mesh name: %s", attribs->getAttributeAsString("Mesh").c_str());
	Logger::info("\tOnReadUserData name: %s", attribs->getAttributeAsString("name").c_str());

	stringc meshName = attribs->getAttributeAsString("Mesh");
	if (meshName.size() == 0)
		meshName = forSceneNode->getName();

	path scenePath = _scenePath + path("/mdl/") + meshName + ".irrmesh";
	attribs->setAttribute("Mesh", scenePath.c_str());

	forSceneNode->deserializeAttributes(attribs);

	attribs->drop();

	return;
}



void SceneSerializer::OnCreateNode(ISceneNode* node) {
	return;

	if (node->getType() == irr::scene::ESNT_MESH) {

		//
		// fix path to irrmesh files, set as relative
		//
		irr::io::IFileSystem* fileSystem = Config::instance().getFS();
		irr::io::IAttributes* attribs = fileSystem->createEmptyAttributes(Config::instance().getIrrDevice()->getVideoDriver());
		node->serializeAttributes(attribs);

		irr::core::stringc meshPath;
		irr::core::stringc meshName = attribs->getAttributeAsString("name");


		Logger::info("OnCreateNode: %s", node->getName());

		if (!attribs->existsAttribute("Mesh")) {
			Logger::info("OnCreateNode Mesh: NOT FOUND");
			attribs->drop();
			return;
		}

		Logger::info("OnCreateNode attr count: %d", attribs->getAttributeCount());
		for (uint i=0; i < attribs->getAttributeCount(); ++i)
			Logger::info("OnCreateNode attr: %s -> %s", attribs->getAttributeName(i),
					attribs->getAttributeAsString(i).c_str());

		Logger::info("OnCreateNode attr Mesh: %s", attribs->getAttributeAsString("Mesh").c_str());

		node->deserializeAttributes(attribs);
		attribs->drop();
		Logger::info("OnCreateNode: %s end", node->getName());
	}
	return;
}



irr::io::IAttributes* SceneSerializer::createUserData(ISceneNode* forSceneNode) {

	irr::io::IFileSystem* fileSystem = Config::instance().getFS();
	irr::io::IAttributes* attribs = fileSystem->createEmptyAttributes(Config::instance().getIrrDevice()->getVideoDriver());
	forSceneNode->serializeAttributes(attribs);

	Logger::info("\t createUserData mesh name: %s", attribs->getAttributeAsString("Mesh").c_str());
	Logger::info("\t createUserData name: %s", attribs->getAttributeAsString("name").c_str());

	Logger::info("\t createUserData attr count: %d", attribs->getAttributeCount());
	for (uint i=0; i < attribs->getAttributeCount(); ++i)
		Logger::info("\t createUserData attr: %s -> %s", attribs->getAttributeName(i),
				attribs->getAttributeAsString(i).c_str());

	attribs->drop();

	return attribs;
}

