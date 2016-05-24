#pragma once
#include "GameObject.h"
#include "cocos2d.h"


class Hero : public GameObject {

	private:
		int money;

	public:
		Hero(std::string, int, int, int, int);
		int getMoney();
		void setMoney(int);
};