#include<iostream>
#include<windows.h>
#include<fstream>
#include<cstring>
#include<iomanip>  
#include<conio.h>  
#include"Game.h"
#include"Map.h"
#include"Record.h"
#include<windows.h>
#pragma warning(disable:4996)
using namespace std;
extern Record List4[500];
extern Record List5[500];
extern Record List6[500];
static int number4;
static int number5;
static int number6;
enum Input {Up=72,Down=80,Left=75,Right = 77};
void Game::CopyList(ifstream&inf,Record *r,int&n)                       //���ļ����ѡ�ֶ������
{
	int count = 0;
	while(inf.good())
	{
		r[count++].Fin(inf);
	}
	n = count-1;                                      //ѡ����
}
void Game::FlushList(ofstream&of,Record *r,int&n )                   //��������Ժ��ѡ��������ļ���ȥ
{
	for(int i =0;i<n;i++)
	{
		of<<r[i].Player<<'*'<<r[i].Max<<'*'<<r[i].Score<<'*'<<r[i].Rank<<endl;
	}
}
int Game:: Mune()
{
	system("cls");
	system("color 3f");
	system("mode con cols=56 lines=20"); 
	system("title 2048 ");
	cout<<"������������������������������������������������������\n";
	cout<<"��                  Game     2048                   ��\n";
	cout<<"��[1]��4*4ģʽ                                      ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[2]��5*5ģʽ                                      ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[3]��6*6ģʽ                                      ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[4]���˳�                                         ��\n";
	cout<<"������������������������������������������������������\n";
	cout<<"��ѡ��";
	if(cin.fail()){cin.clear();cin.sync();}
	int select;
	cin>>select;
	return select;
}
Game::Game(bool a){
	Continue = a;
}
void Game::Start()
{
	int flag = 0;
	Exwhile = true;
	while(Exwhile)
	{
		int Choice = Mune();
		switch(Choice)
		{
		case 1: Exwhile = false; flag = 1; break;
		case 2: Exwhile = false; flag = 2; break;
		case 3: Exwhile = false; flag = 3; break;
		case 4: Exwhile = false; Exit();  break;
		default:cout<<"�����������������"<<endl;cin.clear();cin.sync();system("pause 2>nul"); break;  
		}
        if (flag==1)             //�����־����1��˵��ΪС�����
			{
				Small();        
			}
	 	else if (flag==2)		  //�����־����2��˵��Ϊ�������
			{
				Medium();
			}
		else if (flag==3)		  //�����־����2��˵��Ϊ�������
			{
				Big();
			}
		flag = 0;
	}
}
void Game::Exit(){
	system("cls");
	Continue = false;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"������������������������������������������������������\n";
	cout<<"��          ��л��ʹ�ã�  2048 С��Ϸ               ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[��������]: 춳ǳǳǳ�                            ��\n";
	cout<<"��[��ϵQ Q ]: 1090414006                            ��\n";
	cout<<"��[��ϵ����]��yuxumin980417@126.com                 ��\n";
	cout<<"��[��˵��]����Ϸ�������棬лл����ʹ�ã�          ��\n";
	cout<<"������������������������������������������������������\n";
	cout<<"��л����ʹ�ã�лл����������˳���Ϸ...\n"; 
}
void Game::Small()
{
	system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"������������������������������������������������������\n";
		cout<<"��                                                  ��\n";
		cout<<"��                ��Ϸ������*���˳�                 ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	system("pause>nul 2>nul");          
	system("cls");                                 //����
	system("title 2048  Small Size");     //�޸Ĵ��ڱ���
	system("color 3f");                            //���崰����ɫ
	system ("mode con cols=30 lines=13");          //���ô��ڴ�С
	Map MyMap;
	MyMap.SetSize(4);
	MyMap.InitMap();
	MyMap.RandomNum(2);
	cout<<MyMap;
	while(!MyMap.DecideDeath())           //ͨ������֪���������ҵĵ�һ������ASCIIΪ224
	{
		int dir = getch();
		if(dir != 224&&dir!=42)     {cout<<"   ������󣡣�"<<endl;continue;}
		else if(dir == 42)          break;
		else
			switch(dir = getch())
			{
			case Input::Up: Up(MyMap);break;
			case Input::Down:Down(MyMap);break;
			case Input::Left:Left(MyMap);break;
			case Input::Right:Right(MyMap);break;
			default:cout<<"�ۣ����ָ��������ô�ڼ������ҵ��ģ�"<<endl;break;
			}
		system("cls");    
		if(MoveOrNot())       //ֻ�б����ƶ���  �Ų����µ�����
			MyMap.RandomNum(1);
		cout<<MyMap;
	}
	cin.clear();
	cin.sync();
	RecordPlay4(MyMap);
	ifstream CopySource;
	CopySource.open("PlayerRecord4.txt",ios_base::in);
	CopyList(CopySource,List4,number4);
	CopySource.close();
	/*-------------------------��List���� ��Score ��Max------------------------------------*/
  	ListSort(List4,number4);
	/*-------------------------������������ļ���ȥ ------------------------------------*/
	ofstream OutSource;
	OutSource.open("PlayerRecord4.txt",ios_base::trunc);
	FlushList(OutSource,List4,number4);
	OutSource.close();
	/*----------------------------����������� -------------------------------------------*/
	FinishGame(MyMap,GetRank(MyMap,List4,number4));
}
void Game::Medium()
{
	system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"������������������������������������������������������\n";
		cout<<"��                                                  ��\n";
		cout<<"��                ��Ϸ������*���˳�                 ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	system("pause>nul 2>nul");      
	system("cls");                                 //����
	system("title 2048  Medium Size");     //�޸Ĵ��ڱ���
	system("color 3f");                            //���崰����ɫ
	system ("mode con cols=35 lines=15");          //���ô��ڴ�С
	Map MyMap;
	MyMap.SetSize(5);
	MyMap.InitMap();
	MyMap.RandomNum(2);
	cout<<MyMap;
	while(!MyMap.DecideDeath())           //ͨ������֪���������ҵĵ�һ������ASCIIΪ224
	{
		int dir = getch();
		if(dir != 224&&dir!=42)     {cout<<"   ������󣡣�"<<endl;continue;}
		else if(dir == 42)          break;
		else
			switch(dir = getch())
			{
			case Input::Up: Up(MyMap);break;
			case Input::Down:Down(MyMap);break;
			case Input::Left:Left(MyMap);break;
			case Input::Right:Right(MyMap);break;
			default:cout<<"�ۣ����ָ��������ô�ڼ������ҵ��ģ�"<<endl;break;
			}
		system("cls");    
		if(MoveOrNot())       //ֻ�б����ƶ���  �Ų����µ�����
			MyMap.RandomNum(1);
		cout<<MyMap;
		if(MyMap.DecideDeath())
			cout<<"Death";
	}
	cin.clear();
	cin.sync();
	RecordPlay5(MyMap);
	ifstream CopySource;
	CopySource.open("PlayerRecord5.txt",ios_base::in);
	CopyList(CopySource,List5,number5);
	CopySource.close();
	/*-------------------------��List���� ��Score ��Max------------------------------------*/
	ListSort(List5,number5);
	/*-------------------------������������ļ���ȥ ------------------------------------*/
	ofstream OutSource;
	OutSource.open("PlayerRecord5.txt",ios_base::trunc);
	FlushList(OutSource,List5,number5);
	OutSource.close();
	/*----------------------------����������� -------------------------------------------*/
	FinishGame(MyMap,GetRank(MyMap,List5,number5));
}
void Game::Big()
{

	system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"������������������������������������������������������\n";
		cout<<"��                                                  ��\n";
		cout<<"��                ��Ϸ������*���˳�                 ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	system("pause>nul 2>nul");      
	system("cls");                                 //����
	system("title 2048  Big Size");     //�޸Ĵ��ڱ���
	system("color 3f");                            //���崰����ɫ
	system ("mode con cols=40 lines=20");          //���ô��ڴ�С
	Map MyMap;
	MyMap.SetSize(6);
	MyMap.InitMap();
	MyMap.RandomNum(2);
	cout<<MyMap;
	while(!MyMap.DecideDeath())           //ͨ������֪���������ҵĵ�һ������ASCIIΪ224
	{
		int dir = getch();
		if(dir != 224&&dir!=42)     {cout<<"   ������󣡣�"<<endl;continue;}
		else if(dir == 42)          break;
		else
			switch(dir = getch())
			{
			case Input::Up: Up(MyMap);break;
			case Input::Down:Down(MyMap);break;
			case Input::Left:Left(MyMap);break;
			case Input::Right:Right(MyMap);break;
			default:cout<<"�ۣ����ָ��������ô�ڼ������ҵ��ģ�"<<endl;break;
			}
		system("cls");    
		if(MoveOrNot())       //ֻ�б����ƶ���  �Ų����µ�����
			MyMap.RandomNum(1);
		cout<<MyMap;
		if(MyMap.DecideDeath())
			cout<<"Death";
	}
	cin.clear();
	cin.sync();
	RecordPlay6(MyMap);
	ifstream CopySource;
	CopySource.open("PlayerRecord6.txt",ios_base::in);
	CopyList(CopySource,List6,number6);
	CopySource.close();
	/*-------------------------��List���� ��Score ��Max------------------------------------*/
	ListSort(List6,number6);
	/*-------------------------������������ļ���ȥ ------------------------------------*/
	ofstream OutSource;
	OutSource.open("PlayerRecord6.txt",ios_base::trunc);
	FlushList(OutSource,List6,number6);
	OutSource.close();
	/*----------------------------����������� -------------------------------------------*/
	FinishGame(MyMap,GetRank(MyMap,List6,number6));
}
void Game::FinishGame(Map&M,int R)
{
	system("cls");
	system("mode con cols=56 lines=20"); 
	system("title 2048 ");
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"������������������������������������������������������\n";
	cout<<"��               ��Ϸ����  GameOver                 ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��                �÷֣�"<<setw(8)<<M.Score<<"                    ��\n";
	cout<<"��               �������"<<setw(7)<<M.Max<<"                    ��\n";
 	cout<<"��                ������    "<<setw(3)<<R<<"                     ��\n";
	cout<<"��                                                  ��\n";
	cout<<"������������������������������������������������������\n";
	cout<<"��л����ʹ�ã�лл������������ز˵�...\n";
	system("pause>nul 2>nul");          
}
void Game::RecordPlay4(Map&M)
{
	ofstream Setfile;
	Setfile.open("PlayerRecord4.txt",ios_base::app);
	system("cls");
	system("mode con cols=56 lines=20"); 
	system("title 2048 ");
	cout<<endl;
	cout<<endl;
	cout<<"������������������������������������������������������\n";
	cout<<"��   ������������֣�                               ��\n";
	cout<<"������������������������������������������������������\n";
	char TempName[20];
	cin.getline(TempName,19);
	if(strcmp(TempName,"")==0)   strcpy(TempName,"�������");
	Record NewRecord(TempName,M.Max,M.Score);
	NewRecord.Fout(Setfile);
	Setfile.close();
}
void Game::RecordPlay5(Map&M)
{
	ofstream Setfile;
	Setfile.open("PlayerRecord5.txt",ios_base::app);
	system("cls");
	system("mode con cols=56 lines=20"); 
	system("title 2048 ");
	cout<<endl;
	cout<<endl;
	cout<<"������������������������������������������������������\n";
	cout<<"��   ������������֣�                               ��\n";
	cout<<"������������������������������������������������������\n";
	char TempName[20];
	cin.getline(TempName,19);
	if(strcmp(TempName,"")==0)   strcpy(TempName,"�������");
	Record NewRecord(TempName,M.Max,M.Score);
	NewRecord.Fout(Setfile);
	Setfile.close();
}
void Game::RecordPlay6(Map&M)
{
	ofstream Setfile;
	Setfile.open("PlayerRecord6.txt",ios_base::app);
	system("cls");
	system("mode con cols=56 lines=20"); 
	system("title 2048 ");
	cout<<endl;
	cout<<endl;
	cout<<"������������������������������������������������������\n";
	cout<<"��   ������������֣�                               ��\n";
	cout<<"������������������������������������������������������\n";
	char TempName[20];
	cin.getline(TempName,19);
	if(strcmp(TempName,"")==0)   strcpy(TempName,"�������");
	Record NewRecord(TempName,M.Max,M.Score);
	NewRecord.Fout(Setfile);
	Setfile.close();
}
void Game::ListSort(Record *list,int n )
{
	for(int i = 0;i<n-1;i++)
		for(int j = i;j<n;j++)
			if(list[i].Score < list[j].Score)              //�ȱȽ�һ��Score
				Change(list[i],list[j]);
			else if(list[i].Score == list[j].Score)          //Score��ͬʱ�ñȽ�Max        �ɴ�С����
			{
				if(list[i].Max < list[j].Max)
					Change(list[i],list[j]);
			}
			else ;
	for(int i = 0;i<n;i++)                        //����
		list[i].Rank = i+1 ;
}
int Game::GetRank(Map&M,Record *list,int n)
{
	for(int i = 0 ; i<n;i++)
	{
		if(M.Max == list[i].Max && M.Score == list[i].Score )  return list[i].Rank;
	}
	return -1;
}




