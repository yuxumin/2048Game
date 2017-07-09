#include<iostream>
#include<cmath>
#include<ctime>
#include"Game.h"
#include"Map.h"
#include"Operator.h"
#include"Random.h"
#include"Record.h"
using namespace std;
Record List4[500];
Record List5[500];
Record List6[500];
int main()
{
	Game first(true);
	while(first.Continue)
	{
		first.Start();
	}
	return 0;
}

