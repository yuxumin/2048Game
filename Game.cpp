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
	cout<<"┌—————————————————————————┐\n";
	cout<<"│                  Game     2048                   │\n";
	cout<<"│[1]、4*4模式                                      │\n";
	cout<<"│                                                  │\n";
	cout<<"│[2]、5*5模式                                      │\n";
	cout<<"│                                                  │\n";
	cout<<"│[3]、6*6模式                                      │\n";
	cout<<"│                                                  │\n";
	cout<<"│[4]、退出                                         │\n";
	cout<<"└—————————————————————————┘\n";
	cout<<"请选择：";
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
		default:cout<<"输入错误，请重新输入"<<endl;cin.clear();cin.sync();system("pause 2>nul"); break;  
		}
        if (flag==1)             //如果标志等于1，说明为小型面板
			{
				Small();        
			}
	 	else if (flag==2)		  //如果标志等于2，说明为中型面板
			{
				Medium();
			}
		else if (flag==3)		  //如果标志等于2，说明为大型面板
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
	cout<<"┌—————————————————————————┐\n";
	cout<<"│          感谢您使用：  2048 小游戏               │\n";
	cout<<"│                                                  │\n";
	cout<<"│[程序制作]: 於城城城城                            │\n";
	cout<<"│[联系Q Q ]: 1090414006                            │\n";
	cout<<"│[联系邮箱]：yuxumin980417@126.com                 │\n";
	cout<<"│[简单说明]：游戏结束界面，谢谢您的使用！          │\n";
	cout<<"└—————————————————————————┘\n";
	cout<<"感谢您的使用，谢谢！按任意键退出游戏...\n"; 
}
void Game::Small()
{
	system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"┌—————————————————————————┐\n";
		cout<<"│                                                  │\n";
		cout<<"│                游戏中输入*键退出                 │\n";
		cout<<"│                                                  │\n";
		cout<<"└—————————————————————————┘\n";
	system("pause>nul 2>nul");          
	system("cls");                                 //清屏
	system("title 2048  Small Size");     //修改窗口标题
	system("color 3f");                            //定义窗口颜色
	system ("mode con cols=30 lines=13");          //设置窗口大小
	Map MyMap;
	MyMap.SetSize(4);
	MyMap.InitMap();
	MyMap.RandomNum(2);
	cout<<MyMap;
	while(!MyMap.DecideDeath())           //通过资料知道上下左右的第一个公共ASCII为224
	{
		int dir = getch();
		if(dir != 224&&dir!=42)     {cout<<"   输入错误！！"<<endl;continue;}
		else if(dir == 42)          break;
		else
			switch(dir = getch())
			{
			case Input::Up: Up(MyMap);break;
			case Input::Down:Down(MyMap);break;
			case Input::Left:Left(MyMap);break;
			case Input::Right:Right(MyMap);break;
			default:cout<<"哇，这个指令你是怎么在键盘上找到的？"<<endl;break;
			}
		system("cls");    
		if(MoveOrNot())       //只有本轮移动过  才产生新的数字
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
		cout<<"┌—————————————————————————┐\n";
		cout<<"│                                                  │\n";
		cout<<"│                游戏中输入*键退出                 │\n";
		cout<<"│                                                  │\n";
		cout<<"└—————————————————————————┘\n";
	system("pause>nul 2>nul");      
	system("cls");                                 //清屏
	system("title 2048  Medium Size");     //修改窗口标题
	system("color 3f");                            //定义窗口颜色
	system ("mode con cols=35 lines=15");          //设置窗口大小
	Map MyMap;
	MyMap.SetSize(5);
	MyMap.InitMap();
	MyMap.RandomNum(2);
	cout<<MyMap;
	while(!MyMap.DecideDeath())           //通过资料知道上下左右的第一个公共ASCII为224
	{
		int dir = getch();
		if(dir != 224&&dir!=42)     {cout<<"   输入错误！！"<<endl;continue;}
		else if(dir == 42)          break;
		else
			switch(dir = getch())
			{
			case Input::Up: Up(MyMap);break;
			case Input::Down:Down(MyMap);break;
			case Input::Left:Left(MyMap);break;
			case Input::Right:Right(MyMap);break;
			default:cout<<"哇，这个指令你是怎么在键盘上找到的？"<<endl;break;
			}
		system("cls");    
		if(MoveOrNot())       //只有本轮移动过  才产生新的数字
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
		cout<<"┌—————————————————————————┐\n";
		cout<<"│                                                  │\n";
		cout<<"│                游戏中输入*键退出                 │\n";
		cout<<"│                                                  │\n";
		cout<<"└—————————————————————————┘\n";
	system("pause>nul 2>nul");      
	system("cls");                                 //清屏
	system("title 2048  Big Size");     //修改窗口标题
	system("color 3f");                            //定义窗口颜色
	system ("mode con cols=40 lines=20");          //设置窗口大小
	Map MyMap;
	MyMap.SetSize(6);
	MyMap.InitMap();
	MyMap.RandomNum(2);
	cout<<MyMap;
	while(!MyMap.DecideDeath())           //通过资料知道上下左右的第一个公共ASCII为224
	{
		int dir = getch();
		if(dir != 224&&dir!=42)     {cout<<"   输入错误！！"<<endl;continue;}
		else if(dir == 42)          break;
		else
			switch(dir = getch())
			{
			case Input::Up: Up(MyMap);break;
			case Input::Down:Down(MyMap);break;
			case Input::Left:Left(MyMap);break;
			case Input::Right:Right(MyMap);break;
			default:cout<<"哇，这个指令你是怎么在键盘上找到的？"<<endl;break;
			}
		system("cls");    
		if(MoveOrNot())       //只有本轮移动过  才产生新的数字
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
	cout<<"┌—————————————————————————┐\n";
	cout<<"│               游戏结束  GameOver                 │\n";
	cout<<"│                                                  │\n";
	cout<<"│                得分："<<setw(8)<<M.Score<<"                    │\n";
	cout<<"│               最大数："<<setw(7)<<M.Max<<"                    │\n";
	cout<<"│                                                  │\n";
	cout<<"└—————————————————————————┘\n";
	cout<<"感谢您的使用，谢谢！按任意键返回菜单...\n";
	system("pause>nul 2>nul");          
}

