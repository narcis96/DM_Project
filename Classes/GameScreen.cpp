#include "GameScreen.h"


USING_NS_CC;

int GameScreen::levelNumber = 0;

Scene* GameScreen::createScene(int levelNumner) {
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	
	// 'layer' is an autorelease object
	auto layer = GameScreen::create();

	// add layer as a child to scene
	scene->addChild(layer);

	GameScreen::levelNumber = levelNumber;

	// return the scene
	return scene;
}

/* void GameScreen::addBox(int i, int j) {
	auto box = Director::getInstance()->getTextureCache()->textureForKey("box.png");
	auto boxSprite = Sprite::createWithTexture(box);
	boxSprite->setPosition(i, j);
	boxSprite->setContentSize(Size(50, 50));
	background->addChild(boxSprite, 0);
} */

// on "init" you need to initialize your instance
bool GameScreen::init() {

	if (!Layer::init()) {
		return false;
	}
	
	



	level = new Level(1);
	renderer = new WorldRenderer(this, level);
	renderer->render();

	
	
	
	/*
	Size visibleSize = Director::getInstance()->getVisibleSize();

	
	Texture2D *bgTexture = Director::getInstance()->getTextureCache()->addImage("road.jpg");
	Director::getInstance()->getTextureCache()->addImage("box.png");
	
	const Texture2D::TexParams tp = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };

	// add "HelloWorld" splash screen"
	int scale = 5;
	background = Sprite::createWithTexture(bgTexture, CCRectMake(0, 0, scale * visibleSize.width, scale * visibleSize.height));
	

	background->getTexture()->setTexParameters(&tp);
	// position the sprite on the center of the screen
	background->setPosition(scale * visibleSize.width / 2, scale * visibleSize.height / 2);

	// add the sprite as a child to this layer
	this->addChild(background, 1);
	
	stance = "left";
	heroSprite = Sprite::create("police_car.png");
	heroSprite->setPosition(Vec2(scale * visibleSize.width / 2 + origin.x, scale * visibleSize.height / 2 + origin.y));
	heroSprite->setScale(0.25f);
	background->addChild(heroSprite, 0);


	for (int i = 0; i <= 20; i++) {
		addBox(100 * i, 0);
	}
	*/

	auto eventListener = EventListenerKeyboard::create();


	eventListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {

		if (keys.find(keyCode) == keys.end()){
			keys[keyCode] = std::chrono::high_resolution_clock::now();
		}
	};

	eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
		keys.erase(keyCode);
	};


	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, renderer->getHeroSprite());
	
	this->scheduleUpdate();

	
	return true;
}

bool GameScreen::isKeyPressed(EventKeyboard::KeyCode code) {
	// Check if the key is currently pressed by seeing it it's in the std::map keys
	// In retrospect, keys is a terrible name for a key/value paried datatype isnt it?
	if (keys.find(code) != keys.end())
		return true;
	return false;
}

double GameScreen::keyPressedDuration(EventKeyboard::KeyCode code) {
	if (!isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL))
		return 0;  // Not pressed, so no duration obviously

	// Return the amount of time that has elapsed between now and when the user
	// first started holding down the key in milliseconds
	// Obviously the start time is the value we hold in our std::map keys
	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - keys[code]).count();
}

void GameScreen::update(float delta) {

	auto heroSprite = renderer->getHeroSprite();

	Camera::getDefaultCamera()->setPosition(heroSprite->getPosition());
	CCLOG("cam2 = %f %f\n", Camera::getDefaultCamera()->getContentSize().width, Camera::getDefaultCamera()->getContentSize().height);

	int rotateSpeed = 300;
	int amount = 500;

	auto position = heroSprite->getPosition();

	if (isKeyPressed(EventKeyboard::KeyCode::KEY_A)) {
		heroSprite->setRotation((int)(heroSprite->getRotation() - rotateSpeed * delta) % 360);
	}

	
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_D)) {
		heroSprite->setRotation((int)(heroSprite->getRotation() + rotateSpeed * delta) % 360);
	}
	
	float angle = -1.0f * heroSprite->getRotation();
	position.x += amount * cos(angle * atan(1) * 4 / 180) * delta;
	position.y += amount * sin(angle * atan(1) * 4 / 180) * delta;

	


	heroSprite->setPosition(position);

	Camera::getDefaultCamera()->setPosition(heroSprite->getPosition());

	
		
		
}

map<cocos2d::EventKeyboard::KeyCode, chrono::high_resolution_clock::time_point> GameScreen::keys;
	

