#include <SDL2/SDL_mixer.h>
#include <iostream>
using namespace std;

class Music {
public:
  Music();
  ~Music();
  void play();
};

Music::Music() {
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Music *music;
  Mix_AllocateChannels(16);
  Mix_Volume(1, MIX_MAX_VOLUME/2);
  music = Mix_LoadMUS("assets/audio/phased.mp3");
  Mix_PlayMusic(music, -1);
}
Music::~Music() {}

void Music::play() {
  cout << "playing";
}
