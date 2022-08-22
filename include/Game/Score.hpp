#include<iostream>
class Score
{
private:
	int score=0;

public:

	Score(){};
	void mostrarScore(){score++;std::cout<<score<<std::endl;};
};