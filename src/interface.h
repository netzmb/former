/*
 * interface.h
 *
 *  Created on: 11 груд. 2012
 *      Author: moss
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "singleton.h"

#include <irrlicht.h>

using irr::core::stringc;
using irr::core::vector2di;
using irr::core::recti;
using irr::video::ITexture;


class Interface : public Singleton<Interface> {
    public:

	enum GuiTextures {
		GUITEX_STUB,
		GUITEX_MOUSE_CURSOR,
		GUITEX_MINI_LOGO,
		GUITEX_COUNT
	};

    Interface();

    bool init();
    void update();
    void clear();
    void close();

    irr::gui::IGUIEnvironment* getGUI() const { return _device->getGUIEnvironment(); }
    irr::video::ITexture* loadTex(const stringc& texPath);
    void updateMouse();
    bool showMouse() { return _showMouse; }
    void showMouse(bool show) { _showMouse = show; }

    void fadeOutScreen(irr::u32 timeout);
    ITexture* draw2dImage(const stringc& texPath, const vector2di& position=vector2di());

    recti getTexRect(const ITexture* texture);



    private:

    bool _showMouse;

    irr::IrrlichtDevice* _device;
    irr::video::IVideoDriver* _driver;
    irr::gui::IGUIEnvironment* _irrGUI;
    irr::video::ITexture* _guiTex[GUITEX_COUNT];


    irr::io::path _stubPath;
    irr::video::ITexture* _stubTex;
    //irr::scene::ISceneManager* _scenemgr;
    //irr::video::SColor _frameColor;        //
};



#endif /* INTERFACE_H_ */
