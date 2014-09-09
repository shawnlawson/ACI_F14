#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    int bufferSize = 256;
    vector<float> buffer;
    for (int i = 0; i < bufferSize; i++) {
        buffer.push_back(0.0);
    }
    
    gui = new ofxUICanvas();
    gui->addLabel("Controller", OFX_UI_FONT_LARGE);
    gui->addSpacer();
    // ...(name, minimum, maximum, default)
    gui->addSlider("background", 0.0, 255.0, 100.0);
    ofAddListener(gui->newGUIEvent,
                  this,
                  &ofApp::guiEvent);
    gui->addSpacer();
    
    mgX = gui->addMovingGraph("MouseX", buffer, bufferSize, 0.0, ofGetWidth());
    mgY = gui->addMovingGraph("MouseY", buffer, bufferSize, 0.0, ofGetHeight());
    
    
    
    gui->loadSettings("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    mgX->addPoint(x);
    mgY->addPoint(y);
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

void ofApp::exit()
{
    gui->saveSettings("settings.xml");
    delete gui;
}


void ofApp::guiEvent(ofxUIEventArgs &e)
{
    if(e.getName() == "background")
    {
        ofxUISlider *s = e.getSlider();
        ofBackground(s->getScaledValue());
    }
}









