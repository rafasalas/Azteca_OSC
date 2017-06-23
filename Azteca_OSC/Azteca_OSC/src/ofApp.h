#pragma once

#include "ofMain.h"
#include "ofGraphics.h"
#include "ofxOsc.h"
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
		void arco(float res, float ang, float ang_inicial, float ancho, float radius, float centroX, float centroY, float r, float g, float b, float alf);

		int numero_cachos[1000];
		//ofSoundPlayer musica;

		float angulo_posicion;
		float posicion;



		float value[512];
		float* puntero;

private:
		
	ofxOscReceiver	receiver;
	std::string msg;
	std::string addr;
		
};
