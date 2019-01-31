
#include "ofxSimpleGuiContent.h"


ofxSimpleGuiContent::ofxSimpleGuiContent(string name, ofBaseDraws& content, float fixwidth) : ofxSimpleGuiControl(name) {
	this->content = &content;
	this->fixwidth  = fixwidth;
	controlType = "Content";
	setup();
}

void ofxSimpleGuiContent::setup() {
	fixheight = fixwidth * content->getHeight()/content->getWidth();
	setSize(fixwidth, fixheight + config->sliderTextHeight);
}

void ofxSimpleGuiContent::draw(float x, float y) {
    if(content == NULL) return;
    
	if(content->getWidth() == 0 && content->getHeight() ==0) return;
	
	setPosition(x, y);
	setup();
	
	ofPushMatrix();
	ofTranslate(x, y, 0);
	ofEnableAlphaBlending();
	ofFill();
	glColor4f(0, 0, 0, 0.8f);
	ofDrawRectangle(0, 0, width, fixheight);
	
	ofSetHexColor(0xffffff);
	content->draw(0, 0, width, fixheight);
	
	ofFill();
	setTextBGColor();
	ofDrawRectangle(0, fixheight, width, config->sliderTextHeight);
	
	setTextColor();
	ofDrawBitmapString(name, 3, fixheight + 15);
	ofDisableAlphaBlending();
	ofPopMatrix();
}
