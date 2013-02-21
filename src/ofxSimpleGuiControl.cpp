#include "ofxSimpleGuiControl.h"


ofxSimpleGuiControl::ofxSimpleGuiControl(string name) {
	controlType = "";
	this->config = &defaultSimpleGuiConfig;
	setName(name);
	setKey(key);
	setPosition(0, 0);
	lock	  = false;
	focused	  = false;
	newColumn = false;
	setKeyboardShortcut(0);

	setup();
	
	disableAllEvents();		// just for safety to make sure nothing is registered twice
//	enableAppEvents();
//	enableMouseEvents();
//	disableKeyEvents();
}

ofxSimpleGuiControl &ofxSimpleGuiControl::setConfig(ofxSimpleGuiConfig *config) {
	this->config = config;
	setup();
	return *this;
}

ofxSimpleGuiControl &ofxSimpleGuiControl::setNewColumn(bool b) {
	newColumn = b;
	return *this;
}



ofxSimpleGuiControl &ofxSimpleGuiControl::setName(string newName) {
	name = newName;
	origName = name;
	if(key.compare("") == 0) setKey("");	// if key has not been set yet, set name as key too
	
	hasTitle = (name.compare("") != 0);
	return *this;
}


ofxSimpleGuiControl &ofxSimpleGuiControl::setKey(string newKey) {
	if(newKey.compare("") == 0) key = name;
	else key = newKey;
	for(int i=0; i<key.size(); i++) {
		if(key[i] == ' ') key[i] = '_';
	}
	return *this;
}

ofxSimpleGuiControl &ofxSimpleGuiControl::setTextColor(bool clickable) {
	if(isMouseOver() && clickable) ofSetHexColor(config->textOverColor);
	else ofSetHexColor(config->textColor);
	return *this;
}

ofxSimpleGuiControl &ofxSimpleGuiControl::setTextBGColor(bool clickable) {
	if(isMouseOver() && clickable) ofSetHexColor(config->textBGOverColor);
	else ofSetHexColor(config->textBGColor);
	return *this;
}

ofxSimpleGuiControl &ofxSimpleGuiControl::setFullColor(bool forceActive) {
	if(isMousePressed() || forceActive) ofSetHexColor(config->fullActiveColor);
	else if(isMouseOver()) ofSetHexColor(config->fullOverColor);
	else ofSetHexColor(config->fullColor);
	return *this;
}

ofxSimpleGuiControl &ofxSimpleGuiControl::setEmptyColor() {
	ofSetHexColor(config->emptyColor);
	//		if(isMouseOver()) ofSetHexColor(config->overColor.r, config->overColor.g, config->overColor.b);
	//		if(focused && !isMouseOver()) ofSetHexColor(config->focusColor.r, config->focusColor.g, config->focusColor.b);
	return *this;
}

ofxSimpleGuiControl &ofxSimpleGuiControl::setKeyboardShortcut(char c) {
	keyboardShortcut = c;
	if(c) {
	//	printf("ofxSimpleGuiControl::setKeyboardShortcut %s %c\n", name.c_str(), c);
		name = origName + " (" + c + ")";
	} else {
		name = origName;
	}
	return *this;
}

