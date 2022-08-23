#include"Game/Score.hpp"

Score::Score(){

};

void Score::coinScore(){
    score++;
    std::cout<<score<<std::endl;
};
void Score::enemyScore(){
    score+=5;
    std::cout<<score<<std::endl;
};
void Score::finalScore(){
    
    if(guardado==false){
        std::cout<<"Puntaje final: "<<score<<std::endl;
        readScore();
        saveScore();
        guardado=true;
        
    }    
}
TpList Score::initNodo(int num){
    TpList nuevo = NULL;
	nuevo = new(struct nodo);
	nuevo->nro = num;
	nuevo->sgte = NULL;
    std::cout<<"guardado"<<std::endl;
	return nuevo;
}
void Score::insertScore(int num){
    TpList q = initNodo(num);
	if ( points!= NULL)
		q->sgte = points;
	points = q;
}
void Score::readScore(){    
    std::string line;
    std::ifstream text("records.txt");
    int num;
    insertScore(score);
	if (text.fail()) {
		return;
	}
	while (!text.eof()){
		std::getline(text, line);
        std::from_chars(line.c_str(),line.c_str()+line.length(),num);
        insertScore(num);
	}
	text.close();
}

void Score::saveScore(){
    std::ofstream text;
	text.open("records.txt", std::ios::out);
	while (points != NULL) {
		text << points->nro<<std::endl;
		points = points->sgte;
	}
	text.close();
}