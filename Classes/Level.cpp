#include "Level.h"
#include "Hero.h"
#include "Obstacle.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
USING_NS_CC;


const float Level::scale = 100;
Hero* Level::getHero() {
	return hero;
}


void Level::convert(const float &x, const float &y,float &newX,float &newY) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	float totalWidth = scaleX * visibleSize.width;
	float totalHeight = scaleY * visibleSize.height;
	newX = totalWidth* x / (scale*scaleX);
	newY = totalHeight*y / (scale*scaleY);

	newX += visibleSize.width;
	newY += visibleSize.height;
}
void Level::addObstacle(std::string texture,const float &x, const float &y) {
	float newX, newY;
	convert(x, y, newX, newY);
	objects.push_back(new Obstacle(texture, newX, newY, 1 * blockWidth, 1 * blockHeight));

}
Level::Level(int levelNumber) {
	this->levelNumber = levelNumber;
	
	//read game objects from file
	string levelName = "levels/level" + to_string(levelNumber) + ".txt";

	string data = FileUtils::getInstance()->getStringFromFile(levelName);
	
	stringstream file(data);
	file >> scaleX;
	file >> scaleY;

	char* texture = new char[100];

	file >> texture;

	backgroundTexturePath = "";

	for (int i = 0; i < strlen(texture); i++) {
		backgroundTexturePath += texture[i];
	}


	CCLOG("%d", backgroundTexturePath.size());
	


	auto visibleSize = Director::getInstance()->getVisibleSize();
	float totalWidth = scaleX * visibleSize.width;
	float totalHeight = scaleY * visibleSize.height;

	blocksX = totalWidth / scale;
	blocksY = totalHeight / scale;

	blockWidth = totalWidth / blocksX;
	blockHeight = totalHeight / blocksY;


	int n;
	file >> n;
	string texturePath;
	float x, y, width, height, newX, newY;

	//read obstacles
	
	for (int i = 0; i < n; i++) {
		file >> texturePath;
		file >> x;
		file >> y;
		file >> width;	
		file >> height;
		convert(x, y, newX, newY);
		objects.push_back(new Obstacle(texturePath, newX, newY, width * blockWidth, height * blockHeight));
	}

	//read police cars

	file >> n;

	for (int i = 0; i < n; i++) {
		file >> texturePath;
		file >> x;
		file >> y;
		convert(x, y, newX, newY);
		policeCars.push_back(new Police(texturePath, newX, newY, 2, 1));
	}


	file >> money;
	file >> requiredMoney;

	for (int i = 0; i < money; i++) {
		x = random(1, (int)scale * scaleX);
		y = random(1, (int)scale * scaleY);
		convert(x, y, newX, newY);

		moneyBills.push_back(new Money("dutzi.jpg", newX, newY, 0.5f, 0.5f));
	}
	

	heroTexturePath = "";
	file >> texture;
	for (int i = 0; i < strlen(texture); i++){
		heroTexturePath += texture[i];
	}
	hero = new Hero(heroTexturePath, (int)(scaleX*Director::getInstance()->getVisibleSize().width / 2),(int)( scaleY*Director::getInstance()->getVisibleSize().height / 2), 10, 20);

	//not an actual texture
	file >> texture;

	//play background music on loop
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(texture, true);

	delete texture;
	

}

string Level::getBackgroundTexturePath() {
	return backgroundTexturePath;
}
string Level::getHeroTexturePath() {
	return heroTexturePath;
}

std::vector<GameObject*> Level::getObjects() {
	return objects;
}

std::vector<Police*> Level::getPoliceCars() {
	return policeCars;
}

std::vector<Money*> Level::getMoneyBills() {
	return moneyBills;
}

int Level::getScaleX() {
	return scaleX;
}

int Level::getScaleY() {
	return scaleY;
}

int Level::getBlocksX() {
	return blocksX;
}

int Level::getBlocksY() {
	return blocksY;
}

int Level::getRequiredMoney() {
	return requiredMoney;
}


float Level::getBlockWidth() {
	return blockWidth;
}

float Level::getBlockHeight() {
	return blockHeight;
}

int Level::getMoney() {
	return money;
}

Level::~Level() {

}
