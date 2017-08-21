#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowPosition(0, 0);
    ofSetWindowShape(800, 800);
    ofSetBackgroundColor(25);
    ofEnableSmoothing();
    cam.setPosition(ofGetViewportWidth()/2, ofGetViewportHeight()/2, 100);
    luz.enable();
    luzd.enable();
   
    
    //gui starter
    ofColor guiColor =(255,255,255);
    gui = new ofxUISuperCanvas("UI Controls");
    //gui->setColorBack(guiColor);
    gui->setColorFill(guiColor);
    gui->addSlider("sphere Size", 700, 10, sphSize);
    gui->addSlider("sphere Reso", 12, 64, sphSize);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    luz.setPosition(ofGetViewportWidth()/2, ofGetViewportHeight()/2, 100);
    luzd.setPosition(ofGetViewportWidth()/2, ofGetViewportHeight()/2, 500);
    for(int i =0; i<p.size();i++){
        p[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    float rot = 0.2 * ofGetFrameNum(); // ofRotate takes degrees

    cam.begin();
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    ofEnableLighting();
    
    ofSetColor(ofColor::white);
    sphere.set(700, 12);
    ofRotateX(rot);
    for (int i = 0 ; i<p.size(); i++) {
       p[i].draw();
        if (p.size() > 10000){
            p.erase(p.begin());
            
        }
    }
    
    vertices = sphere.getMesh().getVertices();
    
    for (int i =0; i < vertices.size(); i++) {
        ofVec3f v = vertices[i];
        if (ofGetFrameNum() % 70 == 0){
            Punto pTemp;
            pTemp.pos = v + ofPoint ( 0,0,0);
            p.push_back(pTemp);
        }
        
       
    }
    
    
    
    
    
    
    
    
    
    
    
    
    ofDisableLighting();
    ofDisableDepthTest();
    cam.end();

    
}
//--------------------------------------------------------------
void ofApp::exit(){
    gui->saveSettings("settings.xml");
    delete gui;
}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e){

//    if (!gui->isHit(0,0)){
//        cam.disableMouseInput();
//    }else{
//        cam.enableMouseInput();
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofSetFullscreen(true);
            break;
        case 's':
            ofSaveScreen("screenshot"+ofToString(ofRandom(0,1000),0)+".png");
            break;
        case 'g':
            gui->toggleVisible();
            break;
        case 'm':
            cam.disableMouseInput();
            
            break;
        case 'n':
            cam.enableMouseInput();
            
            break;
            
    }
}


