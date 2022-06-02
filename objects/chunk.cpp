#include <SDL2/SDL_mixer.h>

class Chunk {
public:
  Chunk(const char *musicFile);
  ~Chunk();
protected:
  Mix_Chunk *chunk;
};

Chunk::Chunk(const char *musicFile) {
  chunk = Mix_LoadMUS(musicFile);
  Mix_PlayMusic(music, -1);
}

Chunk::~Chunk() {}
