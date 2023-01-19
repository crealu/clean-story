#include "shard.hpp"

Shard::Shard() {}

Shard::~Shard() {}

void Shard::setup(SDL_Color shardColor, int x, int y) {
	shape = new FilledTriangle(shardColor, x, y);
	collected = false;
}

void Shard::update() {
	collected = true;
}

void Shard::draw(SDL_Renderer * renderer) {
	if (!collected)
		shape->draw(renderer);
}