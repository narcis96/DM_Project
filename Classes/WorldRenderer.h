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
		void renderPolice(cocos2d::Sprite*);
		void renderMoney(cocos2d::Sprite*);
		cocos2d::Layer* scene;
		Sprite* heroSprite;
		Sprite* background;
		void renderWall();

	public:
		static const cocos2d::Texture2D::TexParams texParams;
		WorldRenderer(cocos2d::Layer* scene, Level* level);
		Sprite* getBackground();
		~WorldRenderer();
		void render();
		Sprite* getHeroSprite();

};
#endif
