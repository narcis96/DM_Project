#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__
#include "cocos2d.h"
#include <string>


class GameObject {
	public:
		GameObject(std::string, int, int, int, int);
		~GameObject();
		
	protected:
		void render() {};
		std::string texture;
		int x, y;
		int width, height;
};
#endif //__GAME_OBJECT__