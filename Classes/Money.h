#ifndef __MONEY__
#define __MONEY__
#include "cocos2d.h"
#include "GameObject.h"

class Money : public GameObject {
public:
	Money(std::string, float, float, float, float);
	void render(cocos2d::Sprite*);

};
#endif // !__Money__

