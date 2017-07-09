#ifndef Record_H
#define Record_H
#include<iostream>
using namespace std;
class Game;
class Record
{
public:
	Record(char *s ="ÎÞÃûÍæ¼Ò",int m  = 0,int n = 0);
	void SetPlayer(char *);
	void SetRank(int);
	void SetGrade(int,int,int);
	void Fin(ifstream& );
	void Fout(ofstream& );
	friend class Game;
	friend void Change(Record&,Record&);
private:
	char Player[20];
	int Rank;
	int Max;
	int Score;
};
#endif // !Game_H