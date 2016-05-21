#include "Level.h"
#include "Hero.h"
#include "Obstacle.h"
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
USING_NS_CC;

Hero* Level::getHero() {
	return hero;
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
	
	//file >> backgroundTexturePath;

	int n;
	file >> n;
	string texturePath;
	int x, y, width, height;

	
	for (int i = 0; i < n; i++) {
		file >> texturePath;
		file >> x;
		file >> y;
		file >> width;	
		file >> height;

		objects.push_back(new Obstacle(texturePath, x, y, width, height));
	}
	heroTexturePath = "";
	file >> texture;
	for (int i = 0; i < strlen(texture); i++){
		heroTexturePath += texture[i];
	}
	hero = new Hero(heroTexturePath, (int)(scaleX*Director::getInstance()->getVisibleSize().width / 2),(int)( scaleY*Director::getInstance()->getVisibleSize().height / 2), 10, 20);

	delete texture;
}

string Level::getBackgroundTexturePath() {
	return backgroundTexturePath;
}
string Level::getHeroTexturePath() {
	return heroTexturePath;
}


int Level::getScaleX() {
	return scaleX;
}

int Level::getScaleY() {
	return scaleY;
}

Level::~Level() {

}
