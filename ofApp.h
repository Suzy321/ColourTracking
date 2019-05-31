#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();


	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	ofVideoGrabber vidGrabber;
	int w = vidGrabber.getWidth();
	int h = vidGrabber.getHeight();

	// Code fragment for tracking a spot with a certain target color. 
	// Our target color is CSS LightPink: #FFB6C1 or (255, 182, 193)
	float rTarget = 255;
	float gTarget = 0;
	float bTarget = 0;

	float rTargetG = 0;
	float gTargetG = 255;
	float bTargetG = 0;

	float rTargetB = 0;
	float gTargetB = 0;
	float bTargetB = 255;


	// these are used in the search for the location of the pixel 
	// whose color is the closest to our target color.
	float leastDistanceSoFar = 255;
	float leastDistanceSoFarG = 255;
	float leastDistanceSoFarB = 255;
	int xOfPixelWithClosestColor = 0;
	int xOfPixelWithClosestColorG = 0;
	int xOfPixelWithClosestColorB = 0;
	int yOfPixelWithClosestColor = 0;
	int yOfPixelWithClosestColorG = 0;
	int yOfPixelWithClosestColorB = 0;
	bool red = false;
	bool green = false;
	bool blue = false;
};
