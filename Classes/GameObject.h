#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__
#include "cocos2d.h"
#include <string>
USING_NS_CC;

class GameObject {
	public:
		GameObject(std::string, int, int, int, int);
		~GameObject();

		virtual void render(cocos2d::Sprite* background);
		
	protected:
		std::string texture;
		int x, y;
		int width, height;
};
#endif //__GAME_OBJECT__