#include "music.hpp"

Music::Music(const char *musicFile) {
  music = Mix_LoadMUS(musicFile);
  Mix_PlayMusic(music, -1);
}

Music::~Music() {}

