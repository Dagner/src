#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate( 60 );
	ofSetVerticalSync( true );
	ofEnableSmoothing();
	ofSetCircleResolution( 100 );
	player = Player(30,10,15,60);
	contender = Contender(750,ofGetHeight()/2,15,60);
	ofHideCursor();
	ofBackground(0, 0, 0);
	launchBall = false;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if(launchBall){
		ball.update(ofGetLastFrameTime());
		contender.update(ball.posx,ball.posy,ball.velx);

		ball.testPaddleCollision(player.posx,player.posy,player.width,player.height);
		ball.testEnemyCollision(contender.posx,contender.posy,contender.width,contender.height);
		
		
		if(ball.leftCollision == true){
			cout << "Choco contra el borde izquierdo" << endl;
			score.enemyScore();
			launchBall =false;
			ball.resetBall();
		} else if(ball.rightCollision == true){
			cout << "Choco contra el borde derecho" << endl;
			score.playerScore();
			launchBall =false;
			ball.resetBall();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	ball.display();
	player.display();
	contender.display();
	ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
	score.display();
	if(!launchBall)
		ofDrawBitmapString("Haz clic para continuar", ofGetWidth()/2, ofGetHeight()/2);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
int h = 0;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	player.setPosition(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	launchBall = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}