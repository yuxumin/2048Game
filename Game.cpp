#include<iostream>
#include<windows.h>
#include<iomanip>  
#include<conio.h>  
#include"Game.h"
#include"Map.h"
#include<windows.h>
#pragma warning(disable:4996)
using namespace std;
enum Input {Up=72,Down=80,Left=75,Right = 77};
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
		if(MyMap.DecideDeath())
			cout<<"Death";
	}
	FinishGame(MyMap);
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
	FinishGame(MyMap);
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
	FinishGame(MyMap);
}
void Game::FinishGame(Map&M)
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
	cout<<"��                                                  ��\n";
	cout<<"������������������������������������������������������\n";
	cout<<"��л����ʹ�ã�лл������������ز˵�...\n";
	system("pause>nul 2>nul");          
}

