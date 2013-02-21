//
// console.cpp
//

#include "console.h"
#include "interface.h"


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

	_conOutput = env->addEditBox(L"",
			//irr::core::recti(5,20,500,390), // size and position
			outRect,
			true, // border
			_consoleWindow,
			Interface::GE_CONSOLE_OUTPUT
			);

	// FIXME disable edit for console output
	_conOutput->setEnabled(true);
	// TODO add console output alignment
	_conOutput->setTextAlignment(irr::gui::EGUIA_UPPERLEFT, irr::gui::EGUIA_LOWERRIGHT);



	_conInput = env->addEditBox(L"",
			//irr::core::recti(5,400,500,500), // size and position
			inRect,
			true, // border
			_consoleWindow,
			Interface::GE_CONSOLE_CMD_LINE
			);

	_conInput->setToolTipText(L"enter console command here");


	return true;
}


void Console::close() {
	return;
}



void Console::writeLine(const wchar_t* text) {
	_conOutput->setText(text);
	//_conOutput->setText(L"test asd");

	return;
}

