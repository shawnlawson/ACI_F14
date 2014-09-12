#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(3);
    
    boombox.loadSound("beat.wav");
    boombox.setMultiPlay(true);
   // boombox.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update()
{
    vector<Particle> hold;
    
    for (int i = 0; i < emitter.size(); i++)
    {
        emitter[i].applyForces();
        emitter[i].update();
    
        if (!emitter[i].destroy)
            hold.push_back(emitter[i]);
    }
    
    emitter.clear();
    emitter = hold;
    hold.clear();
    
//    cerr << emitter.size() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::sandyBrown);
//    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
    
    for (int i = 0; i < emitter.size(); i++) {
        emitter[i].draw();
    }
    
    ofSetColor(ofColor::seaGreen);
    ofRect(0, ofGetHeight()-100, ofGetWidth(), ofGetHeight()-100);
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
void ofApp::mousePressed(int x, int y, int button)
{
    int max = ofRandom(10, 20);
    
    for (int i = 0; i < max; i++) {
        emitter.push_back( Particle(ofVec2f(x, y),
                                    ofVec2f(ofRandom(-20, 20), ofRandom(-20, 20)),
                                    ofColor::salmon));
    }
    boombox.play();
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
