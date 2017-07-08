#include<iostream>
#include<windows.h>
#include<iomanip>   
#include"Map.h"
using namespace std;
extern int Size;
void Map::InitMap()
{
	memset(Status,0,sizeof(Status));
	memset(Number,0,sizeof(Status));
}
ostream&operator << (ostream&output,Map&TempMap)
{
	for(int i=0;i<Size;i++)  
    {  
        for(int j=0;j<Size;j++)  
        cout<<setw(5)<<TempMap.Number[i][j];  
        cout<<endl<<endl;  
    } 
	 cout<<"Max:"<<TempMap.Max<<"  "<<"Score:"<<TempMap.Score<<endl;  
}
void Map::AddScore(int a)
{
	Score += a;
}
void Map::DecideMax(int TempNum)
{
	Max = max(this->Max,TempNum);
}
