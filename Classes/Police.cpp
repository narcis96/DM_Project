#include "Police.h"
#include "GameObject.h"
#include<string>

Police::Police(std::string texture, float x, float y, float width, float height) : GameObject(texture, x, y, width, height) {

}
void Police::setPoliceSprite(cocos2d::Sprite* sprite) {
	policeSprite = sprite;

}

cocos2d::Sprite* Police::getPoliceSprite() {
	return policeSprite;

}

