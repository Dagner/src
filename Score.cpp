
#include "Score.h"
#include "ofGraphics.h"
#include "ofUtils.h"


Score::Score():playerPoints(0),enemyPoints(0),playerTotalScore(0){
}


void Score::playerScore(){
	playerPoints++;
}

void Score::enemyScore(){
	enemyPoints++;
}

void Score::display(){
	ofDrawBitmapString("Player:"+ofToString(playerPoints), 580, 15);
	ofDrawBitmapString("Enemy: " +ofToString(enemyPoints), 580, 30);
}

void Score::resetScore(){
	playerPoints = 0;
	enemyPoints = 0;
}