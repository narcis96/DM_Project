#ifndef __LEVEL__
#define __LEVEL__
#include "GameObject.h"
#include "cocos2d.h"
#include "Hero.h"
#include<vector>
#include<string>


class Level {
	public:
		Level(int levelNumber);
		~Level();
		int getScaleX();
		int getScaleY();
		std::string getBackgroundTexturePath();
		std::string getHeroTexturePath();
		Hero* getHero();
		std::vector<GameObject*> getObjects();

	private:
		int levelNumber;
		int scaleX;
		int scaleY;
		std::vector<GameObject*> objects;
		std::string backgroundTexturePath;
		std::string heroTexturePath;
		Hero* hero;
};
#endif