#include<iostream>
#include<windows.h>
#include"Game.h"
#include<windows.h>
using namespace std;
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
	system("cls");                                 //清屏
	system("title 2048  Small Size");     //修改窗口标题
	system("color 3f");                            //定义窗口颜色
	system ("mode con cols=30 lines=13");          //设置窗口大小
	Map MySmallMap;
	MySmallMap.SetSize(4);
	MySmallMap.InitMap();
	cout<<MySmallMap;
	system("pause");
}
void Game::Medium()
{
	system("cls");                                 //清屏
	system("title 2048  Medium Size");     //修改窗口标题
	system("color 3f");                            //定义窗口颜色
	system ("mode con cols=35 lines=15");          //设置窗口大小
	Map MySmallMap;
	MySmallMap.SetSize(5);
	MySmallMap.InitMap();
	cout<<MySmallMap;
	system("pause");
}
void Game::Big()
{
	system("cls");                                 //清屏
	system("title 2048  Big Size");     //修改窗口标题
	system("color 3f");                            //定义窗口颜色
	system ("mode con cols=40 lines=20");          //设置窗口大小
	Map MySmallMap;
	MySmallMap.SetSize(6);
	MySmallMap.InitMap();
	cout<<MySmallMap;
	system("pause");
}

