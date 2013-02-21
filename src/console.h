/*
 * console.h
 *
 *  Created on: 21 лют. 2013
 *      Author: moss
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "singleton.h"
#include <irrlicht.h>

#include <string>


class Console : public Singleton<Console> {
public:
	bool init(irr::gui::IGUIEnvironment* env);
	void close();

	void toggle() { _consoleWindow->setVisible(!_consoleWindow->isVisible()); }
	void writeLine(const wchar_t* text);
private:
	irr::gui::IGUIWindow*  _consoleWindow;
	irr::gui::IGUIEditBox* _conOutput;
	irr::gui::IGUIEditBox* _conInput;

};



#endif /* CONSOLE_H_ */
