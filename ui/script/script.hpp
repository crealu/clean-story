class Script {
public:
  Script();
  ~Script();
  void update(const char *filename);
  void writeText(int current);
  const char *getText(int current);
  int length;

private:
  string text[12];
};
