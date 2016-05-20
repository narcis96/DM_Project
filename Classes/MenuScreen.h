#ifndef __MENU_SCREEN_H__
#define __MENU_SCREEN_H__

#include "cocos2d.h"

class MenuScreen : public cocos2d::Layer {
	public:
		static cocos2d::Scene* createScene();

		//runs only at the beginning
		virtual bool init();

		// implement the "static create()" method manually
		//CREATE_FUNC is an autorelease Macro
		CREATE_FUNC(MenuScreen);

	private:
		//close button event
		void menuCloseCallback(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
