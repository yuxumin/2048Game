#include<iostream>
#include<windows.h>
#include"Operator.h"
#include"Map.h"
using namespace std;
void Operator::Up(Map&M)          //ע��  �ϲ���������С�ķ���
{
	OneTurnMove = 0;
	for(int i = 0;i<M.Size;i++)
		for(int j = 0 ;j<M.Size;j++)
		{
			if(M.Status[i][j] == 1)            //�ҵ���һ�������ֵ�ש��
				{
					for(int k = i-1;k>=0;k--)       //�������ש�����������ש�飨��������ɨ��
						if(M.Status[k][j] == 1)          //��  ���ש�������ש���������ֵ�
							{
								if(M.Number[k][j] == M.Number[k+1][j])    //������������������ֺ����·�����һ����	
									{
										M.Number[k][j] *= 2;            //����
										M.Number[k+1][j] = M.Status[k+1][j] = 0 ;
										M.DecideMax(M.Number[k][j]);
										M.AddScore(M.Number[k][j]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //���ש�����һ����û�����ֵ�   ����k,j������ָ������0������һ��������
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
	for(int i = M.Size - 1;i>=0;i--)     //�������濪ʼ��
		for(int j = 0 ;j<M.Size;j++)
		{
			if(M.Status[i][j] == 1)            //�ҵ���һ�������ֵ�ש��
				{
					for(int k = i+1;k<M.Size;k++)       //�������ש�����������ש�飨��������ɨ��
						if(M.Status[k][j] == 1)          //��  ���ש�������ש���������ֵ�
							{
								if(M.Number[k][j] == M.Number[k-1][j])    //������������������ֺ����Ϸ�����һ����	
									{
										M.Number[k][j] *= 2;            //����
										M.Number[k-1][j] = M.Status[k-1][j] = 0 ;
										M.DecideMax(M.Number[k][j]);
										M.AddScore(M.Number[k][j]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //���ש�����һ����û�����ֵ�   ����k,j������ָ������0������һ��������
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
			if(M.Status[i][j] == 1)            //�ҵ���һ�������ֵ�ש��
				{
					for(int k = j-1;k>=0;k--)       //�������ש����ߵ�����ש�飨��������ɨ��
						if(M.Status[i][k] == 1)          //��  ���ש�����ש���������ֵ�
							{
								if(M.Number[i][k] == M.Number[i][k+1])    //�����������������ֺ����ҷ�����һ����	
									{
										M.Number[i][k] *= 2;            //����
										M.Number[i][k+1] = M.Status[i][k+1] = 0 ;
										M.DecideMax(M.Number[i][k]);
										M.AddScore(M.Number[i][k]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //���ש�����һ����û�����ֵ�   ����i,k������ָ������0������һ��������
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
			if(M.Status[i][j] == 1)            //�ҵ���һ�������ֵ�ש��
				{
					for(int k = j+1;k<M.Size;k++)       //�������ש����ߵ�����ש�飨��������ɨ��
						if(M.Status[i][k] == 1)          //��  ���ש�����ש���������ֵ�
							{
								if(M.Number[i][k] == M.Number[i][k-1])    //�����������������ֺ����ҷ�����һ����	
									{
										M.Number[i][k] *= 2;            //����
										M.Number[i][k-1] = M.Status[i][k-1] = 0 ;
										M.DecideMax(M.Number[i][k]);
										M.AddScore(M.Number[i][k]);
										OneTurnMove ++;
									}
								else ;
							}
						else                              //���ש�����һ����û�����ֵ�   ����i,k������ָ������0������һ��������
							{
								M.Number[i][k] = M.Number[i][k-1];
								M.Status[i][k] = M.Status[i][k-1];
								M.Number[i][k-1] = M.Status[i][k-1] = 0;
								OneTurnMove ++;
							}
				}
		}
}
bool Operator::MoveOrNot()                  //�ж�һ�������Ƿ���һ�β������ƶ�
{
	if(OneTurnMove == 0) return false;
	else return true;
}



