#ifndef __WORLD_RENDERER__
#define __WORLD_RENDERER__

#include "Level.h"
#include "cocos2d.h"

class WorldRenderer {
	private:
		Level* level;
		void renderBackground();
		void renderObjects(cocos2d::Sprite*);
		void renderHero(cocos2d::Sprite* );
		cocos2d::Layer* scene;

	public:
		static const cocos2d::Texture2D::TexParams texParams;
		WorldRenderer(cocos2d::Layer* scene, Level* level);
		~WorldRenderer();
		void render();

};
#endif
