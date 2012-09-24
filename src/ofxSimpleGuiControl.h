#pragma once

#include "ofxMSAInteractiveObject.h"
#include "ofxSimpleGuiConfig.h"

#ifndef OFXMSAGUI_DONT_USE_XML
#include "ofxXmlSettings.h"
#endif

class ofxSimpleGuiControl : public ofxMSAInteractiveObject {
public:
	string		name;		// Human readable name this is what is displayed on screen (includes keyboard shortcut)
	string		origName;	// the original name (excluding keyboard shortcut)
	string		key;		// Machine readable name (don't change this after creating control, used for saving/loading)
	string		controlType;
	bool		lock;
	bool		focused;
	bool		newColumn;
	bool		hasTitle;
	char		keyboardShortcut;

	ofxSimpleGuiControl(string name);
	ofxSimpleGuiControl& setName(string newName);
	ofxSimpleGuiControl& setKey(string newKey);
	ofxSimpleGuiControl& setConfig(ofxSimpleGuiConfig *config);
	ofxSimpleGuiControl& setNewColumn(bool b);

	ofxSimpleGuiControl& setTextColor(bool clickable = true);
	ofxSimpleGuiControl& setTextBGColor(bool clickable = true);
	ofxSimpleGuiControl& setFullColor(bool forceActive = false);
	ofxSimpleGuiControl& setEmptyColor();
	ofxSimpleGuiControl& setKeyboardShortcut(char c);
	
#ifndef OFXMSAGUI_DONT_USE_XML
	virtual void loadFromXML(ofxXmlSettings &XML) {}
	virtual void saveToXML(ofxXmlSettings &XML) {}
#endif
    
	virtual void setup() {}

	virtual void draw(float x, float y) {}
	virtual void draw() { draw(x, y); }

	virtual void onKeyUp() {}			// up key is pressed
	virtual void onKeyDown() {}			// down key is pressed
	virtual void onKeyLeft() {}			// left key is pressed
	virtual void onKeyRight() {}		// right key is pressed
	virtual void onKeyEnter() {}		// enter key is pressed
	
	
	// from ofxMSAInteractiveObject
	virtual void onRollOver(int x, int y)					{}		// called when mouse enters object x, y, width, height
	virtual void onRollOut()								{}		// called when mouse leaves object x, y, width, height
	virtual void onMouseMove(int x, int y)					{}		// called when mouse moves while over object x, y, width, height
	virtual void onDragOver(int x, int y, int button)		{}		// called when mouse moves while over object and button is down
	virtual void onDragOutside(int x, int y, int button)	{}		// called when mouse moves while outside the object after being clicked on it
	virtual void onPress(int x, int y, int button)			{}		// called when mouse presses while over object
	virtual void onPressOutside(int x, int y, int button)	{}		// called when mouse presses while outside object
	virtual void onRelease(int x, int y, int button)		{}		// called when mouse releases while over object
	virtual void onReleaseOutside(int x, int y, int button)	{}		// called when mouse releases outside of object after being pressed on object
	
	virtual void keyPressed( int key ){}
	virtual void keyReleased( int key ){}
	

protected:
	ofxSimpleGuiConfig	*config;
};

