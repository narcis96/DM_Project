#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__
#include "cocos2d.h"
#include <string>
USING_NS_CC;

class GameObject {
	public:
		GameObject(std::string, float, float, float, float);
		~GameObject();

		virtual void render(cocos2d::Sprite* background);
		std::string getTexture();
		Vec2 getPosition();
		
	protected:
		std::string texture;
		float x, y;
		int width, height;
};
#endif //__GAME_OBJECT__