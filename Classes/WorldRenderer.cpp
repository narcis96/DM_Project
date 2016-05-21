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
	string path = level->getBackgroundTexturePath();
	auto visibleSize = Director::getInstance()->getWinSize();
	CCLOG("%f %f", visibleSize.width, visibleSize.height);

	auto backgroundTexture = Director::getInstance()->getTextureCache()->getTextureForKey(path);
	if (backgroundTexture == NULL) {
		backgroundTexture = Director::getInstance()->getTextureCache()->addImage(path);
	}
	int scaleX = level->getScaleX();
	int scaleY = level->getScaleY();
	
	
	auto background = Sprite::createWithTexture(backgroundTexture, CCRectMake(0, 0, scaleX * visibleSize.width, scaleY * visibleSize.height));


	background->getTexture()->setTexParameters(&texParams);
	// position the sprite on the center of the screen
	background->setPosition(scaleX * visibleSize.width / 2, scaleY * visibleSize.height / 2);

	scene->addChild(background, 0);


	auto hero = Sprite::create(level->getHeroTexturePath());
	
	
	// position the sprite on the center of the screen
	hero->setPosition(scaleX * visibleSize.width / 2, scaleY * visibleSize.height / 2);

	CCLOG("%f %f\n", hero->getPosition().x, hero->getPosition().y);
	
	hero->setScale(0.2f);
	background->addChild(hero);

	Camera::getDefaultCamera()->setPosition(hero->getPosition());
	CCLOG("%f %f\n", Camera::getDefaultCamera()->getPosition().x, Camera::getDefaultCamera()->getPosition().y);
}

void WorldRenderer::renderHero() {


}

void WorldRenderer::render() {
	renderBackground();
	renderHero();
	
}

WorldRenderer::~WorldRenderer() {
}
