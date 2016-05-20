#include "WorldRenderer.h"
#include "Level.h"


WorldRenderer::WorldRenderer(cocos2d::Scene* scene, Level* level) {
	this->level = level;
	this->scene = scene;
}

void WorldRenderer::renderBackground() {
	string path = level->getBackgroundTexturePath();
	CCLOG("%s", path);
}

void WorldRenderer::render() {
	renderBackground();
}

WorldRenderer::~WorldRenderer() {
}
