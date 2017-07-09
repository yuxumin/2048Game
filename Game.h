#ifndef Game_H
#define Game_H
#include"Operator.h"
#include"Random.h"
class Map;
class Record;
using namespace std;
class Game:public Operator,public Random{
public:
	Game(bool);
	int Mune();
	void Exit();
	void Start();
	void Small();
	void Medium();
	void Big();
	void FinishGame(Map&,int);
	void RecordPlay4(Map&);
	void RecordPlay5(Map&);
	void RecordPlay6(Map&);
	void FlushList(ofstream&,Record *,int&);
	void CopyList(ifstream&,Record *,int&);
	void ListSort(Record *,int n);
	int GetRank(Map&,Record*,int);
	bool Continue;
	bool Exwhile;
	friend class Map;
};
#endif // !Game_H