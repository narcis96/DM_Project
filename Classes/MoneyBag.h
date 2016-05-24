#ifndef __MONEY_BAG__
#define __MONEY_BAG__
#include "cocos2d.h"
#include "GameObject.h"

class MoneyBag : public GameObject {
public:
	MoneyBag(std::string, float, float, float, float);
	void render(cocos2d::Sprite*);


};
#endif // !__MONEY_BAG__

