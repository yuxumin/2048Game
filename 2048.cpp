#include<iostream>
#include<cmath>
#include<ctime>
#include"Game.h"
#include"Map.h"
#include"Operator.h"
#include"Random.h"
using namespace std;
int main()
{
	Game first(true);
	while(first.Continue)
	{
		first.Start();
	}
	return 0;
}

