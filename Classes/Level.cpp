#include "Level.h"
#include "Obstacle.h"
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
USING_NS_CC;



Level::Level(int levelNumber) {
	this->levelNumber = levelNumber;
	
	//read game objects from file
	string levelName = "levels/level" + to_string(levelNumber) + ".txt";

	string data = FileUtils::getInstance()->getStringFromFile(levelName);
	
	stringstream file(data);
	file >> scaleX;
	file >> scaleY;

	char* backTexture = new char[100];

	file >> backTexture;
	CCLOG("%s", backTexture);

	backgroundTexturePath = "";

	for (int i = 0; i < strlen(backTexture); i++) {
		backgroundTexturePath += backTexture[i];
	}

	delete backTexture;

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

}

string Level::getBackgroundTexturePath() {
	return backgroundTexturePath;
}


Level::~Level() {

}
