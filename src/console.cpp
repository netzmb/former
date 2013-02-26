//
// console.cpp
//

#include "console.h"
#include "interface.h"
#include "configuration.h"
#include "logger.h"
#include "scripting.h"


using irr::core::position2di;
using irr::core::recti;


bool Console::init(irr::gui::IGUIEnvironment* env) {


	// get one character place size
	const irr::core::dimension2du charSize =  env->getSkin()->getFont()->getDimension(L"M");
	// set console size in chars, 80x25 chars
	const ushort outputRows = 25, outputCols = 80;
	const ushort inputRows = 2, inputCols = 75;
	//const ushort margin = 5; // margin around in px
	// console window top left corner
	const position2di start(5,5);
	const position2di margin(3,2); // margin around in px
	const position2di marginTitle(0,12); // margin from window title

	// console output size in pixels
	const position2di outSize(outputCols * charSize.Width, outputRows * charSize.Height);
	// console input  size in pixels
	const position2di inSize(inputCols * charSize.Width, inputRows * charSize.Height);

	recti consoleRect(start, start+marginTitle+margin+outSize+margin);
	consoleRect += position2di(0, inSize.Y);
	consoleRect += margin;

	recti outRect(start + marginTitle + margin , outSize);
	recti inRect(margin.X,
			outRect.LowerRightCorner.Y,
			inSize.X,
			outRect.LowerRightCorner.Y + inSize.Y);


	_env 		   = env;
	_consoleWindow = NULL;
	_conOutput     = NULL;
	_conInput      = NULL;

    //
    // create console window
    //
	_consoleWindow = env->addWindow(
	//_irrGUI->addWindow(
			//irr::core::recti(0,0,80,25),
			//irr::core::recti(0,0,505,505),
			consoleRect,
			false, // modal
			L"Command console", // title
			NULL, // parent element
			Interface::GE_CONSOLE
			);

	_consoleWindow->setVisible(false);

	_conOutput = env->addEditBox(L"Console output",
			//irr::core::recti(5,20,500,390), // size and position
			outRect,
			true, // border
			_consoleWindow,
			Interface::GE_CONSOLE_OUTPUT
			);


	// TODO set console output non-editable
	//_conOutput->setEnabled(false);

	_conOutput->setWordWrap(true);
	_conOutput->setDrawBorder(true);
	_conOutput->setMultiLine(true);
	_conOutput->setAutoScroll(true);
	_conOutput->setTextAlignment(irr::gui::EGUIA_UPPERLEFT, irr::gui::EGUIA_LOWERRIGHT);
	//_conOutputColor = env->getSkin()->getColor(irr::gui::EGDC_EDITABLE);
	//_conOutputColor = env->getSkin()->getColor(irr::gui::EGDC_HIGH_LIGHT_TEXT);
	_conOutputColor = env->getSkin()->getColor(irr::gui::EGDC_BUTTON_TEXT);


	//env->addScrollBar(false,irr::core::recti(10,0,20,100),_consoleWindow);

	_conInput = env->addEditBox(L"",
			//irr::core::recti(5,400,500,500), // size and position
			inRect,
			true, // border
			_consoleWindow,
			Interface::GE_CONSOLE_CMD_LINE
			);

	_conInput->setToolTipText(L"enter console command here");


	loadCommands();

	return true;
}


void Console::close() {
	_consoleWindow->setEnabled(false);
	_conInput->drop();
	_conOutput->drop();
	_conOutput = NULL;
	_consoleWindow->drop();
	return;
}



void Console::putLine(const std::string& text) {

	if (_conOutput && _conOutput->isVisible()) {

		std::wstring tmp_text(text.begin(), text.end());
		std::wstring oldText(_conOutput->getText());
		// append text

		_conOutput->setText((oldText + std::wstring(L"\n") + tmp_text).c_str());

	}


	return;
}



// TODO implement DRY for StuffManager::getPartDirectories and console script search

bool Console::loadCommands() {
	//
	// get script files list
	//

	irr::io::IFileSystem* _fileSystem = Config::instance().getFS();
	const irr::core::stringc pathFilter("scripts/console");


	for (irr::u32 archIndex=0; archIndex < _fileSystem->getFileArchiveCount(); ++archIndex) {
		const irr::io::IFileList* files = _fileSystem->getFileArchive(archIndex)->getFileList();


		for (irr::u32 fileIndex=0; fileIndex < files->getFileCount(); ++fileIndex) {


			if (!files->getFullFileName(fileIndex).equalsn(pathFilter.c_str(), pathFilter.size()) ||
					files->isDirectory(fileIndex))
				continue;


			const irr::io::path scriptName = files->getFileName(fileIndex);
			const irr::io::path scriptFullName = irr::io::path("data/") + files->getFullFileName(fileIndex);
			const irr::io::path commandName = scriptName.subString(0,scriptName.size()-4); // cut ".lua" at end

			_commands[commandName.c_str()] = scriptFullName.c_str();

			Logger::info("\t Console:: register cmd: %s, %s", commandName.c_str(), scriptFullName.c_str());
		}
	}



	return true;
}


void Console::toggle() {
	_consoleWindow->setVisible(!_consoleWindow->isVisible());

	if (_consoleWindow->isVisible())
		_env->setFocus(_conInput);

	return;
}



bool Console::runCommand(const std::string& command) {

	// TODO stub for cmdlist




	const std::string prefix("-> ");
	const std::string doneMsg("\t [done]");

	//
	// check command existence
	//
	if (_commands.count(command) == 0) {
		putLine(prefix + std::string("unknown command: \"") + command + std::string("\""));
		_conInput->setOverrideColor(irr::video::SColor(128,255,0,0));
		return false;
	}

	//
	// run command
	//
	if(!Scripting::instance().runFile(_commands[command].c_str())) {
		putLine(prefix + std::string("command failed: ") + command);
		_conInput->setOverrideColor(irr::video::SColor(128,255,0,0));
		return false;
	}

	_conInput->setOverrideColor(_conOutputColor);
	putLine(prefix + command + doneMsg);
	_conInput->setText(L"");
	_env->setFocus(_conInput);



	return true;
}

