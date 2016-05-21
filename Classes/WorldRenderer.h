#pragma once
#include "Level.h"
#include "cocos2d.h"

class WorldRenderer {
	private:
		Level* level;
		void renderBackground();
		void renderHero();
		cocos2d::Layer* scene;

	public:
		static const cocos2d::Texture2D::TexParams texParams;
		WorldRenderer(cocos2d::Layer* scene, Level* level);
		~WorldRenderer();
		void render();

};

