#ifndef __END_LEVEL_SCREEN_H__
#define __END_LEVEL_SCREEN_H__

#include "cocos2d.h"

class EndLevelScreen : public cocos2d::Layer {
	public:
		static cocos2d::Scene* createScene(bool);

		//runs only at the beginning
		virtual bool init();

		// implement the "static create()" method manually
		//CREATE_FUNC is an autorelease Macro
		CREATE_FUNC(EndLevelScreen);

	private:
		//close button event
		void menuCloseCallback(Ref* pSender);
		static bool won;
};

#endif // __END_LEVEL_SCREEN_H__
