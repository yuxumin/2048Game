#include<iostream>
#include<cmath>
#include<ctime>
#include"Game.h"
#include"Map.h"
using namespace std;
static int Size;
int main()
{
	Map MyMap;
	Game first(true);
	while(first.Continue)
	{
		first.Start();
	}
	return 0;
}

