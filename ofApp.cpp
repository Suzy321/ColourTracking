#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	vidGrabber.setDeviceID(1);
	vidGrabber.setup(1920, 1080);
}

//--------------------------------------------------------------
void ofApp::update() {
	vidGrabber.update();

	//Do computing only if a new frame was obtained

	if (vidGrabber.isFrameNew()) {
		//Getting pixels
		leastDistanceSoFar = 255;
		leastDistanceSoFarG = 255;
		leastDistanceSoFarB = 255;
		green = false;
		red = false;
		blue = false;
		ofPixels pixels = vidGrabber.getPixelsRef();

		int h = pixels.getHeight();
		int w = pixels.getWidth();

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {

				// Extract the color components of the pixel at (x,y)
				// from myVideoGrabber (or some other image source)
				ofColor colorAtXY = pixels.getColor(x, y);
				float rAtXY = colorAtXY.r;
				float gAtXY = colorAtXY.g;
				float bAtXY = colorAtXY.b;

				// Compute the difference between those (r,g,b) values 
					// and the (r,g,b) values of our target color
				float rDif = rAtXY - rTarget; // difference in reds 
				float gDif = gAtXY - gTarget; // difference in greens 
				float bDif = bAtXY - bTarget; // difference in blues 

								// Compute the difference between those (r,g,b) values 
				// and the (r,g,b) values of our target color
				float rDifG = rAtXY - rTargetG; // difference in reds 
				float gDifG = gAtXY - gTargetG; // difference in greens 
				float bDifG = bAtXY - bTargetG; // difference in blues 

								// Compute the difference between those (r,g,b) values 
				// and the (r,g,b) values of our target color
				float rDifB = rAtXY - rTargetB; // difference in reds 
				float gDifB = gAtXY - gTargetB; // difference in greens 
				float bDifB = bAtXY - bTargetB; // difference in blues 

				// The Pythagorean theorem gives us the Euclidean distance.
				float colorDistanceG =
					sqrt(rDifG*rDifG + gDifG * gDifG + bDifG * bDifG);

				float colorDistance =
					sqrt(rDif*rDif + gDif * gDif + bDif * bDif);

				float colorDistanceB =
					sqrt(rDifB*rDifB + gDifB * gDifB + bDifB* bDifB);

				if (colorDistance < leastDistanceSoFar) {
					leastDistanceSoFar = colorDistance;
					xOfPixelWithClosestColor = x;
					yOfPixelWithClosestColor = y;

				}

				if (colorDistanceG < leastDistanceSoFarG) {
					leastDistanceSoFarG = colorDistanceG;
					xOfPixelWithClosestColorG = x;
					yOfPixelWithClosestColorG = y;
				}
				if (colorDistanceB < leastDistanceSoFarB) {
					leastDistanceSoFarB = colorDistanceB;
					xOfPixelWithClosestColorB = x;
					yOfPixelWithClosestColorB = y;
				}

				if (colorDistance < 150) {
					red = true;
				}
			
				
				if (colorDistanceG < 175) {
					green = true;
				}

				if (colorDistanceB < 150) {
					blue = true;
				}
			}

		}
	}
}


//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	ofSetColor(255);
	vidGrabber.draw(0, 0);
	// Draw a circle at the brightest location.
	ofNoFill();
	ofDrawEllipse(xOfPixelWithClosestColor, yOfPixelWithClosestColor, 40, 40);
	ofDrawEllipse(xOfPixelWithClosestColorG, yOfPixelWithClosestColorG, 100, 100);
	ofDrawEllipse(xOfPixelWithClosestColorB, yOfPixelWithClosestColorB, 200, 200);

	if (red == true) {
		ofDrawCircle(300, 300, 100);
			}
	
	if (green == true) {
		ofDrawCircle(800, 800, 400);
	}
	if (blue == true) {
		ofDrawCircle(0, 100, 200);
	}
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

