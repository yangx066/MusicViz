
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    song.load("song.mp3");
    while (! song.isLoaded()); // spin wheels till loaded
    song.play();
    
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    nBandsToGet = 512;  // up to 512
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
   
    
    // update the sound playing system:
    // ofSoundUpdate();
    
    val = ofSoundGetSpectrum(nBandsToGet);  // get array of floats (1 for each band)
    
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed calue sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        ofBackground(255,800 * fftSmoothed[i],0);

    }


}



float getX (int deg, int radius) {
    float x = radius * cos(ofDegToRad(deg)) + ofGetWidth()/2;
    return (x);
}

float getY (int deg, int radius) {
    float y = radius * sin(ofDegToRad(deg)) + ofGetHeight()/2;
    return (y);
}


//--------------------------------------------------------------
void ofApp::draw(){
    int r = 100;  // radius
    
    // draw the fft results:
    
    
    // cos & sin take RADIANS.
    // 2pi radians would be 2 x 57.2958 x 3.1416 = 360 degrees
    // Therefore to draw a whole circle you would use 0-TWO_PI to draw a whole circle
    
    for (int i = 200;i<300; i++){
        ofSetColor(8000 * fftSmoothed[i]+100,2000 * fftSmoothed[i]+100,0);
        cout<<fftSmoothed[i]<<endl;
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,800 * fftSmoothed[i],800*fftSmoothed[i]);
    
    }
    
    
    
    for (int i = 0;i < 512; i++){
        ofSetColor(0,100,fftSmoothed[i/8]*5000);
        float x1 = getX(i, r);
        float y1 = getY(i, r);
        float x2 = getX(i, r + 1000 * fftSmoothed[i/8]);  // up to 2k larger (theoretically) but it will never get even close
        float y2 = getY(i, r + 1000 * fftSmoothed[i/8]);
        ofDrawLine (x1, y1, x2, y2);  // we only care about bottom 8th of the spectrum

    }
    
    for(int i=0; i<200; i++){
        ofDrawCircle(100+i*10,40*i, 2, (-1 *fftSmoothed[i]) * 200);
        ofSetColor(0, 20*i, 50*i, 10*i);
        ofRotate(ofRandom(0,360));
    }


    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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

