#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto size = 30;
	for (int base_x = -600; base_x <= 600; base_x += 600) {

		for (int base_y = -600; base_y <= 600; base_y += 600) {

			ofPushMatrix();
			ofTranslate(base_x, base_y);

			ofRotateX(ofGetFrameNum() * 0.43);
			ofRotateY(ofGetFrameNum() * 0.65);

			for (int len = 150; len <= 300; len += 150) {

				for (int i = 0; i < 6; i += 1) {

					if (i < 4) {

						ofRotateY(90);
						for (int x = len * -0.5; x < len * 0.5; x += size) {

							for (int y = len * -0.5; y < len * 0.5; y += size) {

								auto location = glm::vec3(x, y, len * 0.5);
								float angle = PI * 0.5 * i;
								auto rotation = glm::rotate(glm::mat4(), angle, glm::vec3(0, 1, 0));
								auto noise_location = glm::vec4(location, 0) * rotation;

								auto noise_value = ofNoise(base_x + noise_location.x * 0.0035, base_y + noise_location.y * 0.0035, noise_location.z * 0.0035, ofGetFrameNum() * 0.025);
								if (noise_value > 0.5) {

									ofFill();
									ofSetColor(239);
									ofDrawRectangle(location, size - 1, size - 1);

									ofNoFill();
									ofSetColor(39);
									ofDrawRectangle(location, size, size);
								}
							}
						}
					}
					else {

						ofRotateX(i == 4 ? 90 : 180);
						for (int x = len * -0.5; x < len * 0.5; x += size) {

							for (int y = len * -0.5; y < len * 0.5; y += size) {

								auto location = glm::vec3(x, y, len * 0.5);
								float angle = i == 4 ? PI * 0.5 : PI * 0.5 * 3;
								auto rotation = glm::rotate(glm::mat4(), angle, glm::vec3(1, 0, 0));
								auto noise_location = glm::vec4(location, 0) * rotation;

								auto noise_value = ofNoise(base_x + noise_location.x * 0.0035, base_y + noise_location.y * 0.0035, noise_location.z * 0.0035, ofGetFrameNum() * 0.025);
								if (noise_value > 0.5) {

									ofFill();
									ofSetColor(239);
									ofDrawRectangle(location, size - 1, size - 1);

									ofNoFill();
									ofSetColor(39);
									ofDrawRectangle(location, size, size);
								}
							}
						}

					}
				}
			}

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}