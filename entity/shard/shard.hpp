class Shard {
public:
	Shard();
	~Shard();
	void setup(SDL_Color shardColor, int x, int y);
	void draw(SDL_Renderer *renderer);
	void update();
	bool collected;
	FilledTriangle *shape;
};

