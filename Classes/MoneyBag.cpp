#include "MoneyBag.h"

MoneyBag::MoneyBag(std::string texture, float x, float y, float width, float height) : GameObject(texture, x, y, width, height) {

}

void MoneyBag::render(cocos2d::Sprite* background) {
	auto objectSprite = Sprite::create(texture);
	auto size = objectSprite->getContentSize();
	//objectSprite->setScaleX(float(width) / size.width  );
	//objectSprite->setScaleY(float(height) / size.height );

	objectSprite->setScale(0.25f);


	objectSprite->setPosition(x, y);
	CCLOG("%f %f\n", x, y);
	auto physicsBody = PhysicsBody::createBox(objectSprite->getContentSize(), PhysicsMaterial(0.5f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setContactTestBitmask(0x06);
	objectSprite->setAnchorPoint(Vec2(0, 0));
	//physicsBody->setDynamic(false);
	objectSprite->setPhysicsBody(physicsBody);
	background->addChild(objectSprite);
}

