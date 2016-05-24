#include "GameObject.h"
#include "cocos2d.h"
#include <string>
USING_NS_CC;

GameObject::GameObject(std::string texture, float x, float y, float width, float height) {
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
	auto size = objectSprite->getContentSize();
	//objectSprite->setScaleX(float(width) / size.width  );
	//objectSprite->setScaleY(float(height) / size.height );

	//objectSprite->setScale(0.25f);
	

	objectSprite->setPosition(x, y);
	CCLOG("%f %f\n", x, y);
	auto physicsBody = PhysicsBody::createBox(objectSprite->getContentSize(), PhysicsMaterial(0.5f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);	
	physicsBody->setContactTestBitmask(0x03);
	objectSprite->setAnchorPoint(Vec2(0, 0));
	//physicsBody->setDynamic(false);
	objectSprite->setPhysicsBody(physicsBody);
	background->addChild(objectSprite);
}

std::string GameObject::getTexture() {
	return texture;
}

Vec2 GameObject::getPosition() {
	return Vec2(x, y);
}

