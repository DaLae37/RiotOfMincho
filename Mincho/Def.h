#pragma once
#define MAP_SIZE 48
enum class STATUE {
	MOVE,
	ATACK,
	NONE,
};
class Def
{
public:
	Def();
	~Def();
	bool map[15][15];
};

