#ifndef Game_H
#define Game_H
#include"Operator.h"
#include"Random.h"
class Map;
class Game:public Operator,public Random{
public:
	Game(bool);
	int Mune();
	void Exit();
	void Start();
	void Small();
	void Medium();
	void Big();
	void FinishGame(Map&);
	bool Continue;
	bool Exwhile;
	friend class Map;
};
#endif // !Game_H