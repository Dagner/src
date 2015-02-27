#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Player.h"
#include "Contender.h"
#include "Score.h"

class ofApp : public ofBaseApp{

	public:
		Ball ball;
		Player player;
		Contender contender;
		Score score;
		bool launchBall;
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
