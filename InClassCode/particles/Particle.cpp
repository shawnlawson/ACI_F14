//
//  Particle.cpp
//  ParticleMadness
//
//  Created by Shawn Lawson on 9/9/14.
//
//

#include "Particle.h"

Particle::Particle()
{
    Particle(ofVec2f(0,0), ofVec2f(0,0), ofColor::white);
}

Particle::Particle(ofVec2f pos, ofVec2f vel, ofColor col)
{
    position = pos;
    velocity = vel;
    color = col;
}

void Particle::draw()
{
    ofCircle(position, 10.0);
}

void Particle::update()
{
    position += velocity;
}