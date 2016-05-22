#include "WorldRenderer.h"
#include "Level.h"
#include "cocos2d.h"

USING_NS_CC;


const cocos2d::Texture2D::TexParams WorldRenderer::texParams = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };

WorldRenderer::WorldRenderer(cocos2d::Layer* scene, Level* level) {
	this->level = level;
	this->scene = scene;
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
	
	
	background = Sprite::createWithTexture(backgroundTexture, CCRectMake(0, 0, scaleX * visibleSize.width, scaleY * visibleSize.height));


	background->getTexture()->setTexParameters(&texParams);
	// position the sprite on the center of the screen
	background->setPosition(scaleX * visibleSize.width / 2, scaleY * visibleSize.height / 2);

	scene->addChild(background, 0);
}

void WorldRenderer::renderHero(cocos2d::Sprite* background) {
    heroSprite = Sprite::create(level->getHeroTexturePath());
	auto visibleSize = Director::getInstance()->getWinSize();

	int scaleX = level->getScaleX();
	int scaleY = level->getScaleY();

	auto origin = Director::getInstance()->getVisibleOrigin();
	// position the sprite on the center of the screen
	heroSprite->setPosition(scaleX * visibleSize.width / 2 /*+origin.x*/, scaleY * visibleSize.height / 2/*+origin.y*/);
	//CCLOG("%f %f ", heroSprite->getPosition().x, heroSprite->getPosition().y);

	heroSprite->setScale(0.5f);

	auto physicsBody = PhysicsBody::createBox(heroSprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	heroSprite->setPhysicsBody(physicsBody);
	background->addChild(heroSprite);


}

void WorldRenderer::renderObjects(cocos2d::Sprite* background) {
	std::vector <GameObject*> objects = level->getObjects();
	for (auto obj : objects) {
		obj->render(background);
	}
}

Sprite* WorldRenderer::getHeroSprite() {
	return heroSprite;
}

void WorldRenderer::render() {
	renderBackground();
	renderHero(background);
	renderObjects(background);
	
}

WorldRenderer::~WorldRenderer() {
}


