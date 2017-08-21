//
//  Punto.cpp
//  ParticleClouds
//
//  Created by Jacobo Heredia on 8/20/17.
//
//

#include "Punto.h"

Punto::Punto(){
    pos = ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    vel.set(ofRandom(-1,1),0,ofRandom(-1,1));
}

void Punto::update(){
    pos+= vel;
}

void Punto::draw(){
    ofSetColor(ofColor::white);

    ofDrawRectangle(pos, 5, 10);
}