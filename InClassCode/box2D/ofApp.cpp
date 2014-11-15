#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.createGround();
    ofSetRectMode(OF_RECTMODE_CENTER);

  }

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
    ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
    float minDis = ofGetMousePressed() ? 300 : 200;
    
    for(int i=0; i<circles.size(); i++) {
        float dis = mouse.distance(circles[i].get()->getPosition());
        if(dis < minDis) circles[i].get()->addRepulsionForce(mouse, 9);
        else circles[i].get()->addAttractionPoint(mouse, 4.0);
        
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetColor(ofColor::peru);
//        circles[i].get()->draw();
        
        ofPushMatrix();
        ofTranslate(circles[i].get()->getPosition().x, circles[i].get()->getPosition().y, 0);
        ofRotate(circles[i].get()->getRotation(), 0, 0, 1);
        //ofCircle(0, 0, radius);
        ofRect(0, 0, 15, 15);
        ofPopMatrix();

    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'c') {
        float r = ofRandom(4, 20);
        circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0, 0.53, 0.1);
        circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
        
    }
    
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
