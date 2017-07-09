#include<iostream>
#include<windows.h>
#include<iomanip>   
#include"Map.h"
#include"Random.h"
using namespace std;
int Direction[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};     //四个方位
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
bool Map::DecideDeath()
{
	//先看看是不是没有方块了
	for(int x = 0;x<Size;x++)
		for(int y = 0 ;y<Size;y++)
			if(Status[x][y] == 0) return false;             //有 没有数字的方块  那我们可以继续游戏
	//再看看是不是不能移动了
	for(int i = 0;i<Size;i++)
		for(int j = 0 ;j<Size;j++)
			for(int k = 0;k<4;k++)  //四个方向
			{
				int TempX = i+Direction[k][0];
				int TempY = j+Direction[k][1];
				if(TempX>=0&&TempX<Size&&TempY>=0&&TempY<Size) //在地图里面
					if(Number[i][j] == Number[TempX][TempY])  return false;
			}
	return true;
}
void Map::RandomNum(int k)
{
	Random R;
	R.random_init();
	while(k--)
	{
		int TempX,TempY;
		TempX = R.random_int(Size);
		TempY = R.random_int(Size);
		if(Status[TempX][TempY] == 0) //这个块上暂时没有数字
		{
			Number[TempX][TempY] = R.random_even(2,4) ;      //产生2或者4
			Status[TempX][TempY] = 1;                      //然后就改变这个砖块的状态
		}
		else k++;
	}
}
