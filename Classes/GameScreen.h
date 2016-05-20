#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "Hero.h"
#include "cocos2d.h"
#include "WorldRenderer.h"
#include "Level.h"

using namespace std;

class GameScreen : public cocos2d::Layer {
	public:
		static cocos2d::Scene* createScene(int level);
		virtual bool init() override;

		// implement the "static create()" method manually
		CREATE_FUNC(GameScreen);
		//runs at every frame 
		void update(float) override;
		bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
		double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);
	
	private:
		WorldRenderer* renderer;
		Level* level;

		static int levelNumber;
		//key press map
		static map<cocos2d::EventKeyboard::KeyCode, chrono::high_resolution_clock::time_point> keys;
		//cocos2d::Sprite* background;
		//void addBox(int i, int j);
};

#endif
