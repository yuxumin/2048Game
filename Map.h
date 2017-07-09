#ifndef Map_H
#define Map_H
#include<iostream>
#include"Random.h"
#include"Operator.h"
using namespace std;
class Map{
public:
	void InitMap();
	void AddScore(int);
	void DecideMax(int);
	void SetSize(int);
	bool DecideDeath();
	void RandomNum(int);        //int表示要产生几个随机数
	friend ostream&operator << (ostream&,Map&);
	friend class Random;
	friend class Operator;
	friend class Game;
private:
	int Max,Score;
	int Size;
	int Status[6][6];
	int Number[6][6];
};
#endif // !Game_H