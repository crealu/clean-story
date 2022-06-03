#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>

class Animation {
public:
	Animation();
	~Animation();
	void draw(SDL_Renderer *renderer);
	void update();
	int t0;
	int t1;
	SDL_Rect rect;
};

Animation::Animation() {
	SDL_Rect aRect = {200, 200, 20, 20};
	rect = aRect;
	t0 = SDL_GetTicks();
	t1 = t0 + 1;
}
Animation::~Animation() {}

void Animation::draw(SDL_Renderer *renderer) {
	t0 = round(SDL_GetTicks() / 1000);
	if (t0 != t1) {
		t1 = t0;
		cout << t0 << endl;
	}
	if (t0 > 1 && t0 < 2) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
		t0 = 0;
	}
}

void Animation::update() {
	
}

// float animatedFPS = 24.0f;
// bool running;
//
// while (running) {
// 	Uint32 current = SDL_GetTicks();
//
// 	// Calculate dT (in seconds)
//
// 	for ( /* objects */ ) {
// 		float dT = (current - object.lastUpdate) / 1000.0f;
//
// 		int framesToUpdate = floor(dT / (1.0f / animatedFPS));
// 		if (framesToUpdate > 0) {
// 			object.lastFrame += framesToUpdate;
// 			object.lastFrame %= object.numFrames;
// 			object.lastUpdate = current;
// 		}
//
// 		render(object.frames[object.lastFrame]);
// 	}
// }
