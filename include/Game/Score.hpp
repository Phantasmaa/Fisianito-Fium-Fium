#pragma once
#include<iostream>
#include <sstream>
#include <fstream>
#include<iostream>
#include<charconv>

struct nodo {
	int nro;
	struct nodo* sgte;
	
};

typedef struct nodo* TpList;

class Score
{
private:
	int score=0,cont=0;
	int bscores[99];
	bool guardado=false;
	TpList points=NULL;

public:
	Score();
	void coinScore();
	void enemyScore();
	void finalScore();
	TpList initNodo(int num);//crear nodo
	void insertScore(int num);//insertar el puntaje en la lista
	void readScore();//lee scores anterioresS
	void saveScore();//guarda los puntajes

};