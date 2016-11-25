#pragma once

#include "ofMain.h"
#include "ofxMaxim.h" //import Maxim Library


struct Note{ //data type that defines group list of variables under one name, in block of memory: to access lots of things under one pointer
    
    maxiOsc osc; //declaring oscillator
    maxiEnv env; //declaring envelope
    double frequency; //declaring frequency, returns double
    
    
    Note(double _f) { //building Note
        
        frequency = _f; //setting frequency
        env.setAttack(1000); ///defining ADSR envelope; Attack time 1 second
        env.setDecay(1); //Decay (must be between 0 and 1)
        env.setSustain(1); //Sustain (must be between 0 and 1)
        env.setRelease(5500); //Release time 5.5 seconds
        
        
    }
    
    inline double play(){ //Function that returns the sound as a double; (inline: takes body of function and wherever it is called it substitutes function); used a lot with maxim library in examples
        
    
        return env.adsr(osc.triangle(frequency), env.trigger); //returns envelope, with a triangle oscillator, env.trigger to trigger the event


        
    }
                
                
                
    inline void on(){ //function that triggers the note to play
        
        env.trigger = 1; //boolean turns trigger on
    }
                
                
    inline void off(){ //function that triggers the note to turn off
        env.trigger = 0; //boolean that turns trigger off
        
                }
                
  
    
    
};




class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void audioOut(float * output, int bufferSize, int nChannels); //Audio Out thread, allows sound to be made, must always use this to play sounds in Maxim
    
        unsigned bufferSize, sampleRate; //declaring global variables so these don't have to be redefined and can be accessed in any .cpp or .h file
    
        double currentSample; //this gets the frame from the buffer
    
        double outputs[2]; //double array for output, left and right stereo, also commonly used when using maxim
    
        maxiMix mix; //defining built in Maxim mixer
        vector<unique_ptr<Note>> notes; //smart pointers, when the struct goes out of scope this will fix that problem, avoids bugs and is optimized
        ofImage face; //defines new image as face
    
};




    
    

