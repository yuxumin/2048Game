#ifndef Operator_H
#define Operator_H
class Map;
class Operator{                  
public:
    void Up(Map&);
	void Down(Map&);
	void Left(Map&);
	void Right(Map&);
	bool MoveOrNot();
	friend class Map;
private:
	int OneTurnMove;
	int TempNumber[6][6],TempStatus[6][6];
	int SMax,Sscore;
};
#endif // !Game_H