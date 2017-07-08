#include<iostream>
#include<windows.h>
#include<iomanip>   
#include"Map.h"
using namespace std;
void Map::InitMap()
{
	memset(Status,0,sizeof(Status));
	memset(Number,0,sizeof(Status));
	Max = 0;
	Score = 0;
}
ostream&operator << (ostream&output,Map&TempMap)
{
	for(int i=0;i<TempMap.Size;i++)  
    {  
        for(int j=0;j<TempMap.Size;j++)  
        output<<setw(5)<<TempMap.Number[i][j];  
        output<<endl<<endl;  
    } 
	 output<<"Max:"<<TempMap.Max<<"  "<<"Score:"<<TempMap.Score<<endl;  
	 return output;
}
void Map::AddScore(int a)
{
	Score += a;
}
void Map::DecideMax(int TempNum)
{
	Max = max(this->Max,TempNum);
}
void Map::SetSize(int S)
{
	Size = S;
}