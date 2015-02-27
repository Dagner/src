#pragma once

class Score {

public:
	int playerPoints;
	int enemyPoints;
	int playerTotalScore;


	Score();

	void playerScore();
	void enemyScore();
	void resetScore();
	void display();

};