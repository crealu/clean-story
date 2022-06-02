#include <SDL2/SDL_mixer.h>

class Music {
public:
  Music(const char *musicFile);
  ~Music();
private:
  Mix_Music *music;
};

Music::Music(const char *musicFile) {
  music = Mix_LoadMUS(musicFile);
  Mix_PlayMusic(music, -1);
}

Music::~Music() {}
