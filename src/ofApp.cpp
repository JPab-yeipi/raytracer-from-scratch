#include "ofApp.h"
#include <vector>

using namespace std;

// implement YOUR logic here ----------------------------------


//-------------------------------------------------------------
void ofApp::setup() {
	
	// Raytracing Settings ------------------------------------
	
	// number of pixels: w x h
	w = 640;
	h = 480;
	
	// where our rays start on the perspective view
	viewpoint = {0, 0, 1};
	
	// screen ranges for x and y
	vector<float> range_x = {-2, 2};
	vector<float> range_y = {-1.5, 1.5};
	
	// camera: parallel = false, perspective = true
	Camera cam(viewpoint, w, h, range_x, range_y, true);

	//---------------------------------------------------------
	
	// geometric shapes ---------------------------------------
	Vec3 center(0, 0, -2);
	Sphere sphere1(center, 2);
	// --------------------------------------------------------
	
	colorPixels.allocate(w, h, OF_PIXELS_RGB);
	
	// color pixels, use x and y to control red and green
	// se recorre cada pixel en pantalla y se colorea de algun color
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			// colorPixels.setColor(x, y, ofColor(x*255/w, y*255/w, 100));
			colorPixels.setColor(x, y, ofColor(50, 168, 82));
			
			// we trace a ray for every pixel in the screen
			Ray actual_r = cam.ray_tracing(x, y);
			
			// t_sphere > 0 if it hit something, -1 if not
			double t_sphere = sphere1.hit_sphere(actual_r);
			
			// we hit the sphere
			if(t_sphere > 0){
				Vec3 t_hit = actual_r.evaluate(t_sphere);
				colorPixels.setColor(x, y, ofColor(43, 78, 194));
			}
		}
	}
	texColor.allocate(colorPixels);
}

/*
inline void color_hit(Ray ra, double t, int pix_x, int pix_y, int R, int G, int B){
	if(t > 0){
		Vec3 t_hit = ra.evaluate(t);
		colorPixels.setColor(pix_x, pix_y, ofColor(R, G, B));
	}
}
*/

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetHexColor(0xffffff);
	texColor.draw(0, 0, w, h);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if(key == 'p'){
		cout << "Projection Mode Activated " << endl;
	}

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
