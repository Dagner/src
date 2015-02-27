
#include "Paddle.h"
#include "ofGraphics.h"

Paddle::Paddle(float x, float y, float w, float h){
	
	posx = x;
	posy = y;
	width = w;
	height = h;

}

Paddle::Paddle(){
	
	posx = 10;
	posy = 10;
	width = 10;
	height = 30;

}



void Paddle::display(){
	ofRect(posx,posy,width,height);
}


void Paddle::setPosition(float x, float y){
	//posx = x;
	posy = y;
}