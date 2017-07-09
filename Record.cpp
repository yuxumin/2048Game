#include<iostream>
#include<fstream>
#include<cstring>
#include"Record.h"
using namespace std;
#pragma warning (disable:4996)
Record::Record(char *s,int m,int n)
{
	strcpy(Player,s);
	Max = m;
	Score = n;
	Rank = -1;
}
void Record::SetPlayer(char *s)
{
	strcpy(Player,s);
}
void Record::SetRank(int r)
{
	Rank = r;
}
void Record::SetGrade(int m,int n,int r )
{
	Max = m;
	Score = n;
	Rank = r;
}
void Record::Fout(ofstream& of)     //存储到文件中去
{
	of<<Player<<'*'<<Max<<'*'<<Score<<'*'<<Rank<<endl;
}
void Record::Fin(ifstream& inf)
{
	char Tempname[20];
	inf.getline(Tempname,19,'*');
	char TempMax[10];
	inf.getline(TempMax,9,'*');
	char Tempscore[20];
	inf.getline(Tempscore,19,'*');
	char TempRank[20];
	inf.getline(TempRank,19);
	int Max,Score,Rank;
	sscanf(TempMax,"%d",&Max);
	sscanf(Tempscore,"%d",&Score);
	sscanf(TempRank,"%d",&Rank);
	this->SetPlayer(Tempname);
	this->SetGrade(Max,Score,Rank);
}
void Change(Record &r1,Record&r2)
{
	char Temp[20];
	int TempMax,TempScore;
	
	strcpy(Temp,r2.Player);
	TempMax = r2.Max;
	TempScore = r2.Score;
	
	strcpy(r2.Player,r1.Player);
	r2.Max = r1.Max;
	r2.Score = r1.Score;
	
	strcpy(r1.Player,Temp);
	r1.Max = TempMax;
	r1.Score = TempScore;

}


