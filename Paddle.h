#pragma once
 
class Paddle {
public:
	float posx;
	float posy;
	float width;
	float height;

	Paddle();
	Paddle(float x, float y, float w, float h);
	void display();
	void setPosition(float x, float y);
	void moveUp();
	void moveDown();
};