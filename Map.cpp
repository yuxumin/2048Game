#include<iostream>
#include<windows.h>
#include<iomanip>   
#include"Map.h"
#include"Random.h"
using namespace std;
int Direction[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};     //�ĸ���λ
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
	//�ȿ����ǲ���û�з�����
	for(int x = 0;x<Size;x++)
		for(int y = 0 ;y<Size;y++)
			if(Status[x][y] == 0) return false;             //�� û�����ֵķ���  �����ǿ��Լ�����Ϸ
	//�ٿ����ǲ��ǲ����ƶ���
	for(int i = 0;i<Size;i++)
		for(int j = 0 ;j<Size;j++)
			for(int k = 0;k<4;k++)  //�ĸ�����
			{
				int TempX = i+Direction[k][0];
				int TempY = j+Direction[k][1];
				if(TempX>=0&&TempX<Size&&TempY>=0&&TempY<Size) //�ڵ�ͼ����
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
		if(Status[TempX][TempY] == 0) //���������ʱû������
		{
			Number[TempX][TempY] = R.random_even(2,4) ;      //����2����4
			Status[TempX][TempY] = 1;                      //Ȼ��͸ı����ש���״̬
		}
		else k++;
	}
}
