#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sampleRate = 44100; //set sample rate to 44100Hz
    bufferSize = 512; //set buffersize, it must be a multiple of 2
    //ofBackground(0); //Setting background as black
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4); //switching on sound stream, always uses same variables in maxim
   
    
    for( int i= 0; i < 9; i++){ //This pushes Note object into vector using a basic for loop, i is number of notes, so in this case we have 9 notes, i.e. 9 objects, if we wanted more or less sounds we can change this number
        
        notes.emplace_back(new Note((i+1) * 15 + 10)); //maxim recommends emplace back instead of push back, as emblace back is optimized; this is determining frequency based on the position in the vector, starting at 25 hz, then 35 hz, then 45hz, etc.
        
        
    }
    
      face.load("/Users/Shared/openFrameworks/apps/myApps/BasicScale/bin/data/Self-Portrait.png");//this loads face image that will be used for background image

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
   
    face.draw(0,0); //draws image in position x= 0 and y= 0
    ofDrawBitmapString("Press the following keys, A S D F G H J K L", 400, 750); //writes text in position x= 400 and y = 750

    
    
}


//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){ //audio thread, always used in maxim
    
    for( int i = 0; i < bufferSize; i++){ //this loops through the buffer
        currentSample=0; //set currentFrame back to 0, to avoid summing up values otherwise we would get the sum of 25 + 35 when key s is pressed, instead of 35, similarily if key f was pressed we would get the sum of 25 + 35 + 45, instead of 45. This would create noise and not a scale.
        
        for (int c = 0; c < notes.size(); c++){ //loop through every sound maker, if c is less than notes.size(i.e. 9) then add 1
            
            currentSample += notes[c]->play()/notes.size(); //this fills in currentSample with sound, returns double; sums up ports to play function, and divides it all by notes.size, i.e. 9
            
            
            
            
            
        }
        
        
        mix.stereo(currentSample, outputs, 0.5); //runs through mixer to be outputted, 0.5 mixes through both channels equally
        
        output[i * nChannels] = outputs[0];  //fills in buffer for left speaker, always used with maxim
        output[i * nChannels + 1] = outputs[1]; //fills in buffer for right speaker, always used with maxim
        
    }
    
   
    
    
}

//--------------------------------------------------------------




void ofApp::keyPressed(int key){
    
    if(key == 'a'){ //if key a is pressed, then turn first note on, therefore play first note at 25 hz
        
        notes[0]->on(); //pointer that turns function on, as declared in struct
        
        
    }
    if(key == 's'){ //if key s is pressed, then turn first note on, therefore play first note at 35 hz

        
        notes[1]->on(); //pointer that turns function on, as declared in struct
        
        
        
    }
    if(key == 'd'){ //if key d is pressed, then turn first note on, therefore play first note at 45 hz

        
        notes[2]->on(); //pointer that turns function on, as declared in struct
        
        
    }
    
    if(key == 'f'){//if key f is pressed, then turn first note on, therefore play first note at 55 hz

        
        notes[3]->on(); //pointer that turns function on, as declared in struct
        
        
    }
    
    
    if(key == 'g'){ //if key g is pressed, then turn first note on, therefore play first note at 65 hz
        
        notes[4]->on(); //pointer that turns function on, as declared in struct
        
        
        
    }
    
    
    
    if(key == 'h'){ //if key h is pressed, then turn first note on, therefore play first note at 75 hz
        
        notes[5]->on(); //pointer that turns function on, as declared in struct
        
        
        
    }
    
    if(key == 'j'){ //if key j is pressed, then turn first note on, therefore play first note at 85 hz
        
        notes[6]->on(); //pointer that turns function on, as declared in struct
        
        
        
    }
    
    
    if(key == 'k'){ //if key k is pressed, then turn first note on, therefore play first note at 95 hz
        
        notes[7]->on(); //pointer that turns function on, as declared in struct
        
        
        
    }
    
    
    
    if(key == 'l'){ //if key l is pressed, then turn first note on, therefore play first note at 105 hz
        
        notes[8]->on(); //pointer that turns function on, as declared in struct
        
        
        
    }
    
    

 
        
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    
    if(key == 'a'){ // if key a is released, then turn function off, therefore untriggering sound
        
        notes[0]->off(); //pointer that turns function off, as declared in struct
        
        
    }
    if(key == 's'){// if key s is released, then turn function off, therefore untriggering sound
        
        notes[1]->off(); //pointer that turns function off, as declared in struct
        
        
        
    }
    if(key == 'd'){// if key d is released, then turn function off, therefore untriggering sound
        
        notes[2]->off(); //pointer that turns function off, as declared in struct
        
        
        
    }
    
    if(key == 'f'){// if key f is released, then turn function off, therefore untriggering sound
        
        notes[3]->off(); //pointer that turns function off, as declared in struct
        
        
    }
    
    
    if(key == 'g'){// if key g is released, then turn function off, therefore untriggering sound
        
        notes[4]->off(); //pointer that turns function off, as declared in struct
        
        
        
    }
    
    
    
    if(key == 'h'){// if key h is released, then turn function off, therefore untriggering sound
        
        notes[5]->off(); //pointer that turns function off, as declared in struct
        
        
        
    }
    
    
    
    if(key == 'j'){// if key j is released, then turn function off, therefore untriggering sound
        
        notes[6]->off(); //pointer that turns function off, as declared in struct
        
        
        
    }
    
    
    if(key == 'k'){// if key k is released, then turn function off, therefore untriggering sound
        
        notes[7]->off(); //pointer that turns function off, as declared in struct
        
        
        
    }
    
    
    
    if(key == 'l'){// if key l is released, then turn function off, therefore untriggering sound
        
        notes[8]->off(); //pointer that turns function off, as declared in struct
        
        
        
    }
    
    
    
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
