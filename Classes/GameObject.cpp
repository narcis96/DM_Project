#include "GameObject.h"
#include "cocos2d.h"
#include <string>
USING_NS_CC;

GameObject::GameObject(std::string texture, int x, int y, int width, int height) {
	this->texture = texture;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}


GameObject::~GameObject() {
}

void GameObject::render(cocos2d::Sprite* background) {
	auto objectSprite = Sprite::create(texture);
	objectSprite->setPosition(x, y);

	auto physicsBody = PhysicsBody::createBox(objectSprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);	
	physicsBody->setDynamic(false);
	objectSprite->setPhysicsBody(physicsBody);
	background->addChild(objectSprite);
}

