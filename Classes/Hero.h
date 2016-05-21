#pragma once
#include "GameObject.h"
#include "cocos2d.h"


class Hero : public GameObject {

	private:
		cocos2d::Sprite* heroSprite;
		
	public:
		Hero(std::string, int, int, int, int);
		cocos2d::Vec2 getPosition();
		float getRotation();
};