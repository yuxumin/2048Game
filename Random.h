#ifndef Random_H
#define Random_H
class Random{
public:
	void random_init();// 使用随机函数前必须初始化随机数种子
	int random_int(int max);// 生成 0 到 max 范围的整数
	int random_int(int min, int max) ;// 生成 min 到 max 范围的整数
	int random_even(int min, int max) ;//生成 min 到 max 范围的偶数  但是min与max都要是一个偶数
};
#endif // !Game_H