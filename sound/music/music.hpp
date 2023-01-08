#include <SDL2/SDL_mixer.h>

class Music {
public:
  Music(const char *musicFile);
  ~Music();
private:
  Mix_Music *music;
};
