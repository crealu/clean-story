#include <SDL2/SDL_mixer.h>
#include <iostream>
using namespace std;

class Music {
public:
  Music();
  ~Music();
  // Mix_Music getMusic();
protected:
  Mix_Music *music;
};

Music::Music() {
  Mix_Music *music;
  music = Mix_LoadMUS("assets/audio/phased.mp3");
  Mix_PlayMusic(music, -1);
}
Music::~Music() {}
