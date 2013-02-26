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
#include <map>


class Console : public Singleton<Console> {
public:
	bool init(irr::gui::IGUIEnvironment* env);
	void close();

	void toggle();
	void putLine(const std::string& text);

	bool runCommand(const std::string& command);

private:

	bool loadCommands();

	irr::gui::IGUIEnvironment* _env;
	irr::gui::IGUIWindow*  _consoleWindow;
	irr::gui::IGUIEditBox* _conOutput;
	irr::gui::IGUIEditBox* _conInput;
	irr::video::SColor _conOutputColor;

	std::map<std::string, std::string> _commands;

};



#endif /* CONSOLE_H_ */
