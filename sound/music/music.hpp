class Music {
public:
  Music(const char *musicFile);
  ~Music();
private:
  Mix_Music *music;
};
