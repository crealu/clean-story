#include <SDL2/SDL_mixer.h>

class Chunk {
public:
  Chunk(const char *musicFile);
  ~Chunk();
  void play();
private:
  Mix_Chunk *chunk;
};

Chunk::Chunk(const char *musicFile) {
  chunk = Mix_LoadWAV(musicFile);
  // Mix_PlayChannel(-1, chunk, 0);
}

Chunk::~Chunk() {}

void Chunk::play() {
  Mix_PlayChannel(-1, chunk, 0);
}
