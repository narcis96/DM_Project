#pragma once
#include "Level.h"
#include "cocos2d.h"

class WorldRenderer {
	private:
		Level* level;
		void renderBackground();
		cocos2d::Scene* scene;

	public:
		WorldRenderer(cocos2d::Scene* scene, Level* level);
		~WorldRenderer();
		void render();

};

