#ifndef Random_H
#define Random_H
class Random{
public:
	void random_init();// ʹ���������ǰ�����ʼ�����������
	int random_int(int max);// ���� 0 �� max ��Χ������
	int random_int(int min, int max) ;// ���� min �� max ��Χ������
	int random_even(int min, int max) ;//���� min �� max ��Χ��ż��  ����min��max��Ҫ��һ��ż��
};
#endif // !Game_H