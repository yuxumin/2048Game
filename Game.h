#ifndef Game_H
#define Game_H
#include"Map.h"
#include"Operator.h"
#include"Random.h"
class Game:public Operator,public Random{
public:
	Game(bool a);
	int Mune();
	void Exit();
	void Start();
	void Small();
	void Medium();
	void Big();
	void FlushMap(){}
	bool Continue;
	bool Exwhile;
	friend class Map;
};
#endif // !Game_H