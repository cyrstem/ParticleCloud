#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Punto.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
    //GUI StaFF
        void exit();
        void guiEvent(ofxUIEventArgs &e);
        
    //camara
    ofEasyCam cam;
    //luz
    ofLight luz, luzd;
    //main esfera
    ofSpherePrimitive sphere;
    

	//my classs
    vector<Punto> p;
    //postion store around sphere
    
    vector<ofVec3f> vertices;
    
    //GUI staff
    ofxUISuperCanvas *gui;
    int sphSize, sphRes;
    float rotCam;
    //fbo window control
 
};
