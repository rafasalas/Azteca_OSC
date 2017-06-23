#include "ofApp.h"
#include "ofGraphics.h"
#include "ofConstants.h"
#include "ofAppRunner.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	//ofBackground(255,255,255);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	ofNoFill();

	ofEnableSmoothing();
	ofEnableAlphaBlending();
	for (int i = 0; i<512; i++)
	{
		numero_cachos[i] = ofRandom(20, 50);
	}


	for (int j = 0; j<512; j++) {

		value[j] = 0;



	}

	//musica.loadSound("musica.mp3");

	//musica.play();
	receiver.setup(6449);
}

//--------------------------------------------------------------
void ofApp::update(){
	float signo;
	
	

	while (receiver.hasWaitingMessages())
	{
		ofxOscMessage m;
		receiver.getNextMessage(&m);

		msg = std::string("/fft_value");
		addr = std::string(m.getAddress());
		//if (addr.compare(msg) == 0) {
		if (msg==addr) {
			for (int j = 0; j<512; j++) {

				value[j] = m.getArgAsFloat(j);

			}
		
		}
	}




	//posicion = musica.getPosition();
	angulo_posicion = posicion * 360;
}

//--------------------------------------------------------------
void ofApp::draw(){

	float angulo, angulo_inicial, angulo_total, radio;
	float suma_espacios;
	float radius, anchus;
	float red, green, blue, alfa;
	red = 243; blue = 21; alfa = 100;
	ofFill();
	ofEnableSmoothing();
	ofSetLineWidth(1);

	ofSetColor(255, 255, 255, 150);
	//ofSetColor(50,50,255,150);
	float resolucion = 1000, x, y, ancho = 8;
	x = ofGetWidth() / 2;
	y = ofGetHeight() / 2;

	for (int i = 10; i<300; i = i + 10) {
		radio = i;
		suma_espacios = (5 / radio)*numero_cachos[i];
		angulo = (360 - suma_espacios) / numero_cachos[i];

		angulo_inicial = (i * 2) + value[i];
		radius = radio;//+(value[i])*.05;
		anchus = ancho;//-(value[i]*0.05);
		green = 230 - (value[i] * 0.8);
		//ofSetColor(0,125,i/2);
		alfa = 30 + (value[i] * 0.8);
		for (int j = 0; j<numero_cachos[i]; j++)
		{
			arco(resolucion, angulo, angulo_inicial, anchus, radius, x, y, red, green, blue, alfa);
			angulo_inicial = angulo + angulo_inicial + 5;
		}


	}
	ofSetColor(red, green, blue, 80);
	ofRect(10, (y * 2) - 20, ofGetWidth() - 30, 8);
	ofSetColor(red, green, blue, 150);
	ofRect(10, (y * 2) - 20, ((ofGetWidth() - 40)*posicion) + 10, 8);

	//arco (resolucion, angulo_posicion, 0, 70, 690,x,y,255,255, 255,255);
}

//--------------------------------------------------------------

void ofApp::arco(float res, float ang, float ang_inicial, float ancho, float radius, float centroX, float centroY, float r, float g, float b, float alf) {




	float angulo_rad;
	float angle;
	float pasos_arco;
	float pasos_iniciales;




	float angulo_inicial_rad;

	ofSetColor(r, g, b, alf);

	float resolucion_paso = (2 * PI) / res;//resolucion del arco

	angulo_rad = ((2 * PI) / 360)*ang;
	angulo_inicial_rad = ((2 * PI) / 360)*ang_inicial;//conversiones a radianes


	pasos_iniciales = angulo_inicial_rad / resolucion_paso;

	pasos_arco = (angulo_rad / resolucion_paso) + pasos_iniciales;


	ofBeginShape();

	for (int i = pasos_iniciales; i < pasos_arco; i++) {
		angle = (i*resolucion_paso);
		ofVertex(centroX + (cos(angle) * radius), centroY + (sin(angle) * radius));
	}

	for (int i = pasos_arco; i > pasos_iniciales; i--) {
		angle = (i*resolucion_paso);
		ofVertex(centroX + (cos(angle) * (radius - ancho)), centroY + (sin(angle) * (radius - ancho)));
	}

	ofEndShape(true);


}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
