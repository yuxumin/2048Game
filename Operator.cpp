#include<iostream>
#include<windows.h>
#include"Operator.h"
#include"Map.h"
using namespace std;
void Operator::Up(Map&M)          //注意  上层是行列码小的方向
{
	OneTurnMove = 0;
	for(int i = 0;i<M.Size;i++)
		for(int j = 0 ;j<M.Size;j++)
		{
			if(M.Status[i][j] == 1)            //找到了一个有数字的砖块
				{
					for(int k = i-1;k>=0;k--)       //看看这个砖块上面的所有砖块（由下往上扫）
						if(M.Status[k][j] == 1)          //哇  这个砖块上面的砖块是有数字的
							{
								if(M.Number[k][j] == M.Number[k+1][j])    //并且这个上面这块的数字和正下方的是一样的	
									{
										M.Number[k][j] *= 2;            //增倍
										M.Number[k+1][j] = M.Status[k+1][j] = 0 ;
										M.DecideMax(M.Number[k][j]);
										M.AddScore(M.Number[k][j]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //这个砖块的上一块是没有数字的   即（k,j）两个指数都是0，把下一块往上移
							{
								M.Number[k][j] = M.Number[k+1][j];
								M.Status[k][j] = M.Status[k+1][j];
								M.Number[k+1][j] = M.Status[k+1][j] = 0;
								OneTurnMove ++;
							}
				}
		}

}
void Operator::Down(Map&M)
{
	OneTurnMove = 0;
	for(int i = M.Size - 1;i>=0;i--)     //从最下面开始找
		for(int j = 0 ;j<M.Size;j++)
		{
			if(M.Status[i][j] == 1)            //找到了一个有数字的砖块
				{
					for(int k = i+1;k<M.Size;k++)       //看看这个砖块下面的所有砖块（由上往下扫）
						if(M.Status[k][j] == 1)          //哇  这个砖块上面的砖块是有数字的
							{
								if(M.Number[k][j] == M.Number[k-1][j])    //并且这个下面这块的数字和正上方的是一样的	
									{
										M.Number[k][j] *= 2;            //增倍
										M.Number[k-1][j] = M.Status[k-1][j] = 0 ;
										M.DecideMax(M.Number[k][j]);
										M.AddScore(M.Number[k][j]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //这个砖块的上一块是没有数字的   即（k,j）两个指数都是0，把下一块往上移
							{
								M.Number[k][j] = M.Number[k-1][j];
								M.Status[k][j] = M.Status[k-1][j];
								M.Number[k-1][j] = M.Status[k-1][j] = 0;
								OneTurnMove ++;
							}
				}
		}

}
void Operator::Left(Map&M)
{
	OneTurnMove = 0;
	for(int i = 0;i<M.Size;i++)
		for(int j = 0 ;j<M.Size;j++)
		{
			if(M.Status[i][j] == 1)            //找到了一个有数字的砖块
				{
					for(int k = j-1;k>=0;k--)       //看看这个砖块左边的所有砖块（由下往上扫）
						if(M.Status[i][k] == 1)          //哇  这个砖块左的砖块是有数字的
							{
								if(M.Number[i][k] == M.Number[i][k+1])    //并且这个左边这块的数字和正右方的是一样的	
									{
										M.Number[i][k] *= 2;            //增倍
										M.Number[i][k+1] = M.Status[i][k+1] = 0 ;
										M.DecideMax(M.Number[i][k]);
										M.AddScore(M.Number[i][k]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //这个砖块的左一块是没有数字的   即（i,k）两个指数都是0，把右一块往上移
							{
								M.Number[i][k] = M.Number[i][k+1];
								M.Status[i][k] = M.Status[i][k+1];
								M.Number[i][k+1] = M.Status[i][k+1] = 0;
								OneTurnMove ++;
							}
				}
		}

}
void Operator::Right(Map&M)
{
	OneTurnMove = 0;
	for(int i = 0;i<M.Size;i++)
		for(int j = M.Size - 1 ;j>=0;j--)
		{
			if(M.Status[i][j] == 1)            //找到了一个有数字的砖块
				{
					for(int k = j+1;k<M.Size;k++)       //看看这个砖块左边的所有砖块（由下往上扫）
						if(M.Status[i][k] == 1)          //哇  这个砖块左的砖块是有数字的
							{
								if(M.Number[i][k] == M.Number[i][k-1])    //并且这个左边这块的数字和正右方的是一样的	
									{
										M.Number[i][k] *= 2;            //增倍
										M.Number[i][k-1] = M.Status[i][k-1] = 0 ;
										M.DecideMax(M.Number[i][k]);
										M.AddScore(M.Number[i][k]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //这个砖块的左一块是没有数字的   即（i,k）两个指数都是0，把右一块往上移
							{
								M.Number[i][k] = M.Number[i][k-1];
								M.Status[i][k] = M.Status[i][k-1];
								M.Number[i][k-1] = M.Status[i][k-1] = 0;
								OneTurnMove ++;
							}
				}
		}
}
bool Operator::MoveOrNot()                  //判断一下现在是否在一次操作有移动
{
	if(OneTurnMove == 0) return false;
	else return true;
}



