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
        for (int y =0; y<h; y++)
        {
            ofColor c = frames[0].getColor(numSlice, y);
            imagePixels.setColor(numSlice, y, c);
        }
        numSlice = (numSlice + 1) % imagePixels.getWidth();
        image.loadData(imagePixels);
        
        //write circular code
        for (int y = 0; y<h; y++)
        {
            for (int x = 0; x<w; x++)
            {
                ofColor c = getPixelColor(x, y);
                imagePixels2.setColor(x, y, c);
            }
        }
        
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
ofColor ofApp::getPixelColor( int x, int y)
{
    int pixX = ofMap(mouseX, 0, ofGetWidth(), 0, grab.getWidth());
    int pixY = ofMap(mouseY, 0, ofGetHeight(), 0, grab.getHeight());
    
    float dist = ofDist(x, y, pixX, pixY);
    
    float f = dist/2.0;
    
    int i0 = int(f);
    int i1 = i0 + 1;
    
    float weight0 = i1 - f;
    float weight1 = 1 - weight0;
    
    int n = frames.size() - 1;
    i0 = ofClamp(i0, 0, n);
    i1 = ofClamp(i1, 0, n);
    
    ofColor color0 = frames[i0].getColor(x, y);
    ofColor color1 = frames[i1].getColor(x, y);
    
    return color0 * weight0 + color1 * weight1;
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
