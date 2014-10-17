#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    video.loadMovie("fingers.mov");
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();
    
    grab.setDeviceID(0);
    grab.initGrabber(320, 240);
    
    image.allocate(320, 240, GL_RGB);
    image2.allocate(320, 240, GL_RGB);
    
    numFrames = 200;
    numSlice = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    
    grab.update();
    
    if (grab.isFrameNew())
    {
        frames.push_front(grab.getPixelsRef());
    }
    
    if (frames.size() > numFrames)
    {
        frames.pop_back();
    }
    
    if (!frames.empty())
    {
        if (!imagePixels.isAllocated()) {
            imagePixels = frames[0];
        }
        
        if (!imagePixels2.isAllocated()) {
            imagePixels2 = frames[0];
        }
        
        int w = frames[0].getWidth();
        int h = frames[0].getHeight();
        
        //write amazing code
        
        
        image.loadData(imagePixels);
        
        //write circular code
        
        image2.loadData(imagePixels2);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(0, 0, video.getWidth(), video.getHeight());
    
    
    ofPixels &pixels = video.getPixelsRef();
    
    ofPushMatrix();
    ofTranslate(video.getWidth()+10, 0);
    for (int x = 0; x<video.getWidth(); x++)
    {
        int pixY = ofMap(mouseY, 0, ofGetHeight(), 0, video.getHeight());
        ofColor c = pixels.getColor(x, pixY);
        ofSetColor(c);
        ofLine(x, 0, x, video.getHeight());
    }
    ofPopMatrix();
    
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(0, video.getHeight() + 10);
    grab.draw(0, 0, grab.getWidth(), grab.getHeight());
    ofTranslate(grab.getWidth()+10, 0);
    image.draw(0, 0);
    ofTranslate(image.getWidth()+10, 0);
    image2.draw(0,0);
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
    mouseX = x;
    mouseY = y;
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
