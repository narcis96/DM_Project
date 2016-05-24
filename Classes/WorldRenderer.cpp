#include "WorldRenderer.h"
#include "Level.h"
#include "cocos2d.h"
#include "Obstacle.h"
#include "Money.h"
USING_NS_CC;


const cocos2d::Texture2D::TexParams WorldRenderer::texParams = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };

WorldRenderer::WorldRenderer(cocos2d::Layer* scene, Level* level) {
	this->level = level;
	this->scene = scene;
}

void WorldRenderer::renderWall() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	float totalWidth = level->getScaleX() * visibleSize.width;
	float totalHeight = level->getScaleY() * visibleSize.height;

	int blocksX = level->getBlocksX();
	int blocksY = level->getBlocksY();

	int blockWidth = level->getBlockWidth();
	int blockHeight = level->getBlockHeight();
	const int plusX = visibleSize.width;
	const int plusY = visibleSize.height;

	auto fenceTexture = Director::getInstance()->getTextureCache()->getTextureForKey("brick.png");

	if (fenceTexture == NULL) {
		fenceTexture = Director::getInstance()->getTextureCache()->addImage("brick.png");
	}

	auto fence = Sprite::createWithTexture(fenceTexture, CCRectMake(0 + plusX, 0 + plusY, level->getScaleX() * visibleSize.width, blockHeight));
	fence->getTexture()->setTexParameters(&texParams);
	fence->setAnchorPoint(Vec2(0, 0));
	fence->setPosition(0 + plusX, 0 + plusY);

	auto physicsBody = PhysicsBody::createBox(fence->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);
	fence->setPhysicsBody(physicsBody);

	background->addChild(fence, 0);


	auto fanceLeft = Sprite::createWithTexture(fenceTexture, CCRectMake(0 + plusX, 0 + plusY, blockWidth, level->getScaleY() * visibleSize.height));
	fanceLeft->getTexture()->setTexParameters(&texParams);
	fanceLeft->setAnchorPoint(Vec2(0, 0));
	fanceLeft->setPosition(0 + plusX, 0 + plusY);


	physicsBody = PhysicsBody::createBox(fanceLeft->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);
	fanceLeft->setPhysicsBody(physicsBody);


	background->addChild(fanceLeft, 0);


	auto fenceRight = Sprite::createWithTexture(fenceTexture, CCRectMake(totalWidth - blockWidth + plusX, 0 + plusY, blockWidth, level->getScaleY() * visibleSize.height));
	fenceRight->getTexture()->setTexParameters(&texParams);
	fenceRight->setAnchorPoint(Vec2(0, 0));
	fenceRight->setPosition(totalWidth - blockWidth + plusX, 0 + plusY);


	physicsBody = PhysicsBody::createBox(fenceRight->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);
	fenceRight->setPhysicsBody(physicsBody);

	background->addChild(fenceRight, 0);



	auto fenceUp = Sprite::createWithTexture(fenceTexture, CCRectMake(0 + plusX, totalHeight - blockHeight + plusY, level->getScaleX() * visibleSize.width, blockHeight));
	fenceUp->getTexture()->setTexParameters(&texParams);
	fenceUp->setAnchorPoint(Vec2(0, 0));
	fenceUp->setPosition(0 + plusX, totalHeight - blockHeight + plusY);


	physicsBody = PhysicsBody::createBox(fenceUp->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setDynamic(false);
	fenceUp->setPhysicsBody(physicsBody);

	background->addChild(fenceUp, 0);
}

void WorldRenderer::renderBackground() {
	std::string path = level->getBackgroundTexturePath();
	auto visibleSize = Director::getInstance()->getWinSize();

	auto backgroundTexture = Director::getInstance()->getTextureCache()->getTextureForKey(path);
	if (backgroundTexture == NULL) {
		backgroundTexture = Director::getInstance()->getTextureCache()->addImage(path);
	}
	int scaleX = level->getScaleX();
	int scaleY = level->getScaleY();
	
	
	background = Sprite::createWithTexture(backgroundTexture, CCRectMake(0, 0, (scaleX + 2) * visibleSize.width, (scaleY + 2) * visibleSize.height));


	background->getTexture()->setTexParameters(&texParams);
	// position the sprite on the center of the screen
	background->setPosition((scaleX + 2) * visibleSize.width / 2, (scaleY + 2) * visibleSize.height / 2);

	scene->addChild(background, 0);
}

void WorldRenderer::renderHero(cocos2d::Sprite* background) {
    heroSprite = Sprite::create(level->getHeroTexturePath());
	//heroSprite->setContentSize(Size(2 * level->getBlockWidth(), level->getBlockHeight()));
	
	auto visibleSize = Director::getInstance()->getWinSize();

	int scaleX = level->getScaleX();
	int scaleY = level->getScaleY();

	auto origin = Director::getInstance()->getVisibleOrigin();
	// position the sprite on the center of the screen
	heroSprite->setPosition(scaleX * visibleSize.width / 2 + visibleSize.width, scaleY * visibleSize.height / 2 + visibleSize.height);
	//CCLOG("%f %f ", heroSprite->getPosition().x, heroSprite->getPosition().y);

	heroSprite->setScale(0.5f);

	auto physicsBody = PhysicsBody::createBox(heroSprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setContactTestBitmask(0x01);
	heroSprite->setPhysicsBody(physicsBody);
	background->addChild(heroSprite);



}

void WorldRenderer::renderPolice(cocos2d::Sprite* background) {
	std::vector<Police*>  police = level->getPoliceCars();
	for (int i = 0; i < police.size(); ++i){
		auto policeTexture = Director::getInstance()->getTextureCache()->getTextureForKey(police[i]->getTexture());
		if (policeTexture == NULL) {
			policeTexture = Director::getInstance()->getTextureCache()->addImage(police[i]->getTexture());
		}

		auto policeSprite = Sprite::createWithTexture(policeTexture);
		police[i]->setPoliceSprite(policeSprite);
		policeSprite->setPosition(police[i]->getPosition());
		//policeSprite->setScale(0.3f);

		auto physicsBody = PhysicsBody::createBox(policeSprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
		physicsBody->setGravityEnable(false);
		physicsBody->setContactTestBitmask(0x02);
		policeSprite->setPhysicsBody(physicsBody);
		
		background->addChild(policeSprite, 1);

	}
	

}
 
void WorldRenderer::renderObjects(cocos2d::Sprite* background) {
	std::vector <GameObject*> objects = level->getObjects();
	for (auto obj : objects) {
		obj->render(background);
	}

}

void WorldRenderer::renderMoney(cocos2d::Sprite* background) {
	for (int i = 0; i < level->getMoneyBills().size(); i++) {
		level->getMoneyBills()[i]->render(background);
	}
}

Sprite* WorldRenderer::getHeroSprite() {
	return heroSprite;
}

Sprite* WorldRenderer::getBackground() {
	return background;
}

void WorldRenderer::render() {
	
	renderBackground();
	renderHero(background);
	renderObjects(background);
	renderPolice(background);
	renderWall();
	renderMoney(background);

}

WorldRenderer::~WorldRenderer() {
}


