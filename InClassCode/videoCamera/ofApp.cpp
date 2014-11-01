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
    
    colorImage.allocate(320, 240);
    grayImage.allocate(320, 240);
    thresh = 80.0;
    
    haarFinder.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){

    video.update();
    
    grab.update();
    
    if (grab.isFrameNew()) {
        frames.push_front(grab.getPixelsRef());
    }
    
    if (frames.size() > numFrames) {
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
        
        
        for (int y = 0; y<h; y++) {
            ofColor c = frames[0].getColor(numSlice, y);
            imagePixels.setColor(numSlice, y, c);
        }
        image.loadData(imagePixels);
        
        numSlice = (numSlice + 1) % 320;
        
        for (int y = 0; y<h; y++) {
            for (int x = 0; x<w; x++) {
                ofColor c = getPixelColor(x, y);
                imagePixels2.setColor(x, y, c);
            }
        }
        image2.loadData(imagePixels2);
        
       // colorImage.setFromPixels(imagePixels2.getPixels(), 320, 240);
        haarFinder.findHaarObjects(imagePixels2.get);
    }

    colorImage.setFromPixels(video.getPixels(), 320, 240);
    grayImage = colorImage;
    grayImage.threshold(thresh);
    grayImage.flagImageChanged();
    //image to search, min area, max area, num blobs, blobs with holes?
    contourFinder.findContours(grayImage, 300, 38400, 10, true);
  
//    haarFinder.findHaarObjects(grab.getPixelsRef());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    video.draw(0, 0, video.width, video.height);
    
    ofPixels &pixels = video.getPixelsRef();
    
    int w = pixels.getWidth();
    int h = pixels.getHeight();
    
    ofPushMatrix();
    ofTranslate(video.width + 10, 0);
    for (int x=0; x<w ; x++) {
        int pixY = ofMap(mouseY, 0, ofGetHeight(), 0, 240);
        cout << pixY << endl;
        ofColor c = pixels.getColor(x, pixY);
        ofSetColor(c);
        ofLine(x, 0, x, h);
    }
    
    ofTranslate(video.width + 10, 0);
    grayImage.draw(0, 0);
    for (int i = 0; i<contourFinder.blobs.size(); i++) {
        contourFinder.blobs[i].draw(0,0);
    }
    
    ofPopMatrix();
    
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(0, video.height+10);
    grab.draw(0, 0, grab.width, grab.height);
    
    for (int i = 0; i < haarFinder.blobs.size(); i++) {
        haarFinder.blobs[i].draw(0,0);
    }
    
    ofSetColor(255);
    
    ofTranslate(grab.width+10, 0);
    image.draw(0,0);
    ofTranslate(grab.width+10, 0);
    image2.draw(0, 0);
    ofPopMatrix();
}

ofColor ofApp::getPixelColor( int x, int y) {
    int pixY = ofMap(mouseY, 0, ofGetHeight(), 0, 240);
    int pixX = ofMap(mouseX, 0, ofGetWidth(), 0, 320);
    
    float dist = ofDist(x, y, pixX, pixY);
    
    float f = dist / 8.0;
    
    int i0 = int(f);
    int i1 = i0 + 1;
    
    float weight0 = i1 - f;
    float weight1 = 1 - weight0;
    
    int n = frames.size() - 1;
    i0 = ofClamp(i0, 0, n);
    i1 = ofClamp(i1, 0, n);
    
    ofColor color0 = frames[ i0 ].getColor( x, y );
    ofColor color1 = frames[ i1 ].getColor( x, y );
    
    ofColor color = color0 * weight0 + color1 * weight1;
    
    return color;
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
    thresh = ofMap(x, 0.0, ofGetWidth(), 0.0, 255.0);
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
