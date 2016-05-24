#ifndef __LEVEL__
#define __LEVEL__
#include "GameObject.h"
#include "cocos2d.h"
#include "Hero.h"
#include "Police.h"
#include "Money.h"
#include<vector>
#include<string>


class Level {
	public:
		Level(int levelNumber);
		~Level();
		int getScaleX();
		int getScaleY();
		int getBlocksX();
		int getBlocksY();
		float getBlockWidth();
		float getBlockHeight();
		std::string getBackgroundTexturePath();
		std::string getHeroTexturePath();
		Hero* getHero();
		std::vector<GameObject*> getObjects();
		std::vector<Police*> getPoliceCars();
		std::vector<Money*> getMoneyBills();
		int getMoney();
		int getRequiredMoney();
		void convert(const float &x, const float &y, float &newX, float &newY);
		void erasePoliceCar(int);
		int getLife();
		void setLife(int);

	private:
		int levelNumber;
		int life;
		int scaleX;
		int scaleY;
		int blocksX;
		int blocksY;
		float blockWidth;
		float blockHeight;
		int money;
		int requiredMoney;
		std::vector<GameObject*> objects;
		std::string backgroundTexturePath;
		std::string heroTexturePath;
		Hero* hero;
		std::vector<Police*> policeCars;
		static const float scale;
		void addObstacle(std::string texture, const float &x, const float &y);
		std::vector<Money*> moneyBills;
};
#endif