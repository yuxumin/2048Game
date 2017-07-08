#ifndef Map_H
#define Map_H
#include<iostream>
using namespace std;
class Map{
public:
	void InitMap();
	void AddScore(int);
	void DecideMax(int);
	void SetSize(int);
	friend ostream&operator << (ostream&,Map&);
private:
	int Max,Score;
	int Size;
	int Status[6][6];
	int Number[6][6];
};
#endif // !Game_H