#ifndef __OBSTACLE__
#define __OBSTACLE__
#include "cocos2d.h"
#include "GameObject.h"

class Obstacle : public GameObject {
	public:
		Obstacle(std::string, int, int, int, int);
		void render(cocos2d::Sprite* );

};
#endif // !__OBSTACLE__

