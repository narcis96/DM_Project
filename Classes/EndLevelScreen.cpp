#include "EndLevelScreen.h"
#include "GameScreen.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIButton.h"

USING_NS_CC;
using namespace ui;

bool EndLevelScreen::won;

Scene* EndLevelScreen::createScene(bool won) {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = EndLevelScreen::create();

	// add layer as a child to scene
	scene->addChild(layer);

	EndLevelScreen::won = won;
	

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool EndLevelScreen::init() {

	if (!Layer::init()) {
		return false;
	}

	//size of GL view
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// add a close button
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(EndLevelScreen::menuCloseCallback, this));
	//set position at the right-bottom corner of the screen
	closeItem->setPosition(Vec2(visibleSize.width - closeItem->getContentSize().width / 2, closeItem->getContentSize().height / 2));

	Label* label;
	if (won)
		label = Label::createWithTTF("Congratulation", "fonts/Vonique_64.ttf", 48);
	else label = Label::createWithTTF("Game Over", "fonts/Vonique_64.ttf", 48);

	// position the label on the center of the screen
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - label->getContentSize().height));
	label->enableShadow();
	label->enableGlow(Color4B::YELLOW);

	// add the label as a child to this layer
	this->addChild(label, 1);

	auto playButton = Button::create("normal_button.png", "pressed_button.png");
	playButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - label->getContentSize().height - 300));

	if (won)
		playButton->setTitleText("Play Next Level");
	else playButton->setTitleText("Replay Level");
	playButton->setTitleFontSize(36);
	playButton->setTitleFontName("fonts/Vonique_64.ttf");

	playButton->addTouchEventListener([&](Ref* sender, Button::TouchEventType eventType) {
		switch (eventType) {
		case ui::Widget::TouchEventType::BEGAN:
			CCLOG("play button begin");
			break;
		case ui::Widget::TouchEventType::ENDED:
			CCLOG("play button clicked");
			//load game screen
			//the parameter is the level of the game
			//now we load level one
			auto gameScreen = GameScreen::createScene(1);

			// Transition Slide In, 1 seconds long
			Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, gameScreen));
			break;
		};
	});

	this->addChild(playButton, 1);


	//add texture to the cache
	auto backgroundTexture = Director::getInstance()->getTextureCache()->addImage("road.jpg");
	//set parameters to repeat the texture
	const Texture2D::TexParams textureParameters = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
	//repreat the texture until it fills the visible screen
	auto background = Sprite::createWithTexture(backgroundTexture, CCRectMake(0, 0, visibleSize.width, visibleSize.height));
	//set the anchor point of the background sprite to origin: 0, 0 coordinates
	background->setAnchorPoint(Vec2(0, 0));
	background->getTexture()->setTexParameters(&textureParameters);

	// add the sprite background as a child to the main layer
	this->addChild(background);

	return true;
}

void EndLevelScreen::menuCloseCallback(Ref* pSender) {
	//console log
	CCLOG("Clicked");
}
