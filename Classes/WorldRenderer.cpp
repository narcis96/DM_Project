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

	auto backgroundTexture = Director::getInstance()->getTextureCache()->getTextureForKey(path);
	if (backgroundTexture == NULL) {
		backgroundTexture = Director::getInstance()->getTextureCache()->addImage(path);
	}
	int scale = 3;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto background = Sprite::createWithTexture(backgroundTexture, CCRectMake(0, 0, scale * visibleSize.width, scale * visibleSize.height));


	background->getTexture()->setTexParameters(&texParams);
	// position the sprite on the center of the screen
	background->setPosition(scale * visibleSize.width / 2, scale * visibleSize.height / 2);

	scene->addChild(background, 0);
	

}

void WorldRenderer::render() {
	renderBackground();
}

WorldRenderer::~WorldRenderer() {
}
