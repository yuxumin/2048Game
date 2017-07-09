#include<iostream>
#include<ctime>
#include"Random.h"
using namespace std;
void Random:: random_init() {
	srand((unsigned int)time(NULL));
}
int Random:: random_int(int max) {
	return rand() % max;
}
int Random::random_int(int min, int max) {       //µ½²»ÁËmax
	int tmin = ((min < max) ? min : max), tmax = ((min < max) ? max : min);
	return tmin + random_int(tmax - tmin);
}
int Random::random_even(int min,int max){
	int tmin = ((min < max) ? min : max), tmax = ((min < max) ? max : min);
	int temp = tmin + random_int(tmax - tmin);
	if(temp%2 ==0)  return temp;
	else return temp -1 ;
}
