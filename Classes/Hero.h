#pragma once
#include "GameObject.h"
#include "cocos2d.h"

using namespace std;

class Hero : public GameObject {

	private:
		cocos2d::Sprite* heroSprite;
		int x, y;
		int width;
		int height;



	public:
		Hero();
		cocos2d::Vec2 getPosition();
		float getRotation();

};