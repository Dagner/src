#pragma once
#include "ofGraphics.h"
#include "ofSoundPlayer.h"

class Ball {
public:
	float posx;
	float posy;
	float prevx;
	float prevy;
	float velx;
	float vely;
	float radius;
	bool leftCollision;
	bool rightCollision;
	ofSoundPlayer bounceSnd;


public:
	Ball(){
		posx = ofGetWidth()/2;
		posy = ofGetHeight()/2;
		velx = 140;
		vely = 140;
		radius = 5;
		leftCollision = false;
		rightCollision = false;
		bounceSnd.loadSound("bounce.mp3");
	}

	void resetBall(){
		posx = ofGetWidth()/2;
		posy = ofGetHeight()/2;
	}

	void update(float delta){
		prevx = posx;
		prevy = posy;
		posx+=velx*delta;
		posy+=vely*delta;
		cout << "posx: " << posx << endl;
		cout << "posy: " << posy << endl;
		testCollision();

	}

	void testCollision(){
		//if(posx + radius < 0 || posx- radius > ofGetWidth()){
			//velx*=-1;
		//}

		leftCollision=false;
		rightCollision =false;

		if(posx +radius < 0){
			velx = 140;
			vely = 140;
			velx*=-1;
			leftCollision = true;
		}


		if(posx -radius > ofGetWidth()){
				velx = 140;
			vely = 140;
			velx*=-1;
			rightCollision = true;
		}

		if(posy < 0 || posy > ofGetHeight()){
			vely*=-1;
		}
	}


	void display(){
		ofCircle(posx,posy,radius);
	}

	void testPaddleCollision(float x, float y, float w, float h){
		if(velx < 0 && posx-radius <= x+w && (posy >= y && posy <=y+h)){
			posx = x+w+radius;
			//velx+=0.2;
			velx*=1.2;
			vely*=1.2;
			velx*=-1;
			bounceSnd.play();
		}
	}

	void testEnemyCollision(float x, float y, float w, float h){
		if(velx > 0 && posx+radius >= x && (posy >= y && posy <=y+h)){
			//posx = x+w;
			//velx+=0.2;
			posx = x-radius;
			velx*=1.2;
			vely*=1.2;
			velx*=-1;
			bounceSnd.play();
		}
	}


};