#include <SDL2/SDL_mixer.h>

class Music {
public:
  Music();
  ~Music();
  void play();
protected:
  Mix_Music *music;
};

Music::Music() {
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_AllocateChannels(16);
  Mix_Volume(1, MIX_MAX_VOLUME/2);
}
Music::~Music() {}

void Music::play() {
  music = Mix_LoadMUS("assets/audio/phased.mp3");
  Mix_PlayMusic(music, -1);
}
