#pragma once
#include "GameObject.h"
#include "cocos2d.h"
#include<vector>
#include<string>

using namespace std;

class Level {
	public:
		Level(int levelNumber);
		~Level();
		int getScaleX();
		int getScaleY();
		string getBackgroundTexturePath();

	private:
		int levelNumber;
		int scaleX;
		int scaleY;
		vector<GameObject*> objects;
		static const cocos2d::Texture2D::TexParams texParams;
		string backgroundTexturePath;
		
};

