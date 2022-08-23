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
	//std::ifstream text;
    std::ifstream text("records.txt");
	//text.open("records.txt", std::ios::in);

    int sum=0;
	bscores[cont] = score;
    cont++;

	if (text.fail()) {
		return;
	}

	while (!text.eof()){
		std::getline(text, line);
		bscores[cont] = std::stoi(line);
		cont++;
	}
	text.close();
}
void Score::saveScore(){
    std::ofstream text;

	text.open("records.txt", std::ios::out);

	/*while (record != NULL) {
		text << record->nro<<std::endl;
		record = record->sgte;
	}*/
    for(int i=0; i<cont;i++){
        std::cout<<bscores[i]<<std::endl;
        text<<bscores[i]<<std::endl;
    }
	text.close();


}