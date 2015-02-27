
#include "Contender.h"
#include "ofAppRunner.h"

Contender::Contender(float x, float y, float w, float h):Paddle(x,y,w,h){
	// La velocidad tiene que ser siempre menor a la de pelota
	vely = 6;
}

Contender::Contender():Paddle(){
}

void Contender::update(float x, float y, float vx){
	float realPosY = posy + (height/2);
	if(vx < 0){
		if(realPosY < ofGetHeight()/2){
			posy+=vely;
		} else if(realPosY > ofGetHeight()/2){
			posy-=vely;
		}
	} else if(vx > 0){
		if(realPosY != y){
			if(y < realPosY){
				posy -= vely;
			} else if(y > realPosY){
				posy += vely;
			}
		}
	}
}