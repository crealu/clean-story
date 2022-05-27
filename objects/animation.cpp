float animatedFPS = 24.0f;
bool running;

while (running) {

	// Event loop

	// Physics loop

	// Rendering loop
	Uint32 current = SDL_GetTicks();

	// Calculate dT (in seconds)

	for ( /* objects */ ) {
		float dT = (current - object.lastUpdate) / 1000.0f;

		int framesToUpdate = floor(dT / (1.0f / animatedFPS));
		if (framesToUpdate > 0) {
			object.lastFrame += framesToUpdate;
			object.lastFrame %= object.numFrames;
			object.lastUpdate = current;
		}

		render(object.frames[object.lastFrame]);
	}
}
