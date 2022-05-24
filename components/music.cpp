#include <SDL2/SDL_mixer.h>
#include <iostream>
using namespace std;

class Music {
public:
  Music(const char *musicFile);
  ~Music();
protected:
  Mix_Music *music;
};

Music::Music(const char *musicFile) {
  music = Mix_LoadMUS(musicFile);
  Mix_PlayMusic(music, -1);
}
Music::~Music() {}
