#include "ofApp.h"


//class to draw square

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::white);
    
    ofSetColor(ofColor::black);
    
    int size = 20;
    
    ofTranslate(100, 100);
    ofPushMatrix();
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            float scaler = j/20.0;
            float newX = ofRandom(-6, 6);
            float newY = ofRandom(-10, 10);
            
            ofPushMatrix();
            ofTranslate(i*size + newX*scaler, j*size + newY*scaler);
            ofPushMatrix();
            ofRotateZ(ofRandom(-scaler*10, scaler*10));
            ofRect(0,0, size, size);
            ofPopMatrix();
            ofPopMatrix();
        }
    }
    ofPopMatrix();
    

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
