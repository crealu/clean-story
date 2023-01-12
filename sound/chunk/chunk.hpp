class Chunk {
public:
  Chunk(const char *musicFile);
  ~Chunk();
  void play();
private:
  Mix_Chunk *chunk;
};
