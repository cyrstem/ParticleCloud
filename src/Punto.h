//
//  Punto.h
//  ParticleClouds
//
//  Created by Jacobo Heredia on 8/20/17.
//
//

#ifndef __ParticleClouds__Punto__
#define __ParticleClouds__Punto__

#include "ofMain.h"
class Punto{
public:
    Punto();
    void update();
    void draw();
    
    ofPoint pos;
    //ofVec3f pos;
    ofVec3f vel;
    vector<int> incre;

};


#endif /* defined(__ParticleClouds__Punto__) */
