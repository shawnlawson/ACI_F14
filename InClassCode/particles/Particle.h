//
//  Particle.h
//  ParticleMadness
//
//  Created by Shawn Lawson on 9/9/14.
//
//

#ifndef __ParticleMadness__Particle__
#define __ParticleMadness__Particle__

#include "ofMain.h"

class Particle {

    ofVec2f position, velocity;
    ofColor color;  
    

public:
    Particle();
    Particle(ofVec2f pos, ofVec2f vel, ofColor col);
    void draw();
    void update();
    
    
    
};


#endif /* defined(__ParticleMadness__Particle__) */