#ifndef __POLICE__
#define __POLICE__
#include "GameObject.h"

class Police : public GameObject {
	public:
		Police(std::string, float, float, float, float);
		void setPoliceSprite(cocos2d::Sprite* );
		cocos2d::Sprite* getPoliceSprite();

private:
	cocos2d::Sprite* policeSprite;
};


#endif