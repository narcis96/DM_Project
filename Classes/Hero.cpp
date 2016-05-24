#include "Hero.h"

Hero::Hero(std::string texture, int x, int y, int width, int height) : GameObject(texture, x, y, width, height) {
	money = 0;
}

int Hero::getMoney() {
	return money;
}

void Hero::setMoney(int money) {
	this->money = money;
}
