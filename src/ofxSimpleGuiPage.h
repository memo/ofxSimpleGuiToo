#pragma once

#include "ofxSimpleGuiIncludes.h"

class ofxSimpleGuiPage : public ofxSimpleGuiControl {
public:
	ofxSimpleGuiPage(string name);
	~ofxSimpleGuiPage();
	
	void						draw(float x, float y, bool alignRight);
	
	ofxSimpleGuiPage&			setXMLName(string xmlFilename);
	void						loadFromXML();
	void						saveToXML();	
	
	
	ofxSimpleGuiControl			&addControl(ofxSimpleGuiControl& control);
	ofxSimpleGuiButton			&addButton(string name, bool &value);
	ofxSimpleGuiContent			&addContent(string name, ofBaseDraws &content, float fixwidth = -1);
	ofxSimpleGuiFPSCounter		&addFPSCounter();
	ofxSimpleGuiQuadWarp		&addQuadWarper(string name, ofBaseDraws &baseDraw, ofPoint *pts);
	//	ofxSimpleGuiMovieSlider		&addMovieSlider(string name, ofVideoPlayer& input);
	ofxSimpleGuiSliderInt		&addSlider(string name, int &value, int min, int max);
	ofxSimpleGuiSliderFloat		&addSlider(string name, float &value, float min, float max);
	ofxSimpleGuiSlider2d		&addSlider2d(string name, ofPoint& value, float xmin, float xmax, float ymin, float ymax);
	ofxSimpleGuiTitle			&addTitle(string name="", float height = 0);
	ofxSimpleGuiToggle			&addToggle(string name, bool &value);
	ofxSimpleGuiColorPicker		&addColorPicker(string name, ofFloatColor& color);
	ofxSimpleGuiComboBox		&addComboBox(string name, int &choice_out, int numChoices, string* choiceTitles=NULL);
	
	void SetEventStealingControl(ofxSimpleGuiControl &control);
	void ReleaseEventStealingControl();
	
	//	void setup(ofEventArgs &e);
	void update(ofEventArgs &e);
	//  void draw(ofEventArgs &e);
	//	void exit(ofEventArgs &e);
	
	void mouseMoved(ofMouseEventArgs &e);
	void mousePressed(ofMouseEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);
	void mouseReleased(ofMouseEventArgs &e);
	
	void keyPressed(ofKeyEventArgs &e);
	void keyReleased(ofKeyEventArgs &e);
	
	
	vector <ofxSimpleGuiControl*>&	getControls();
	
	
protected:
	vector <ofxSimpleGuiControl*>	controls;
	
	//some controls can take over focus (e.g. combo box,) which means events should only be passed to them
	ofxSimpleGuiControl*			eventStealingControl;
	float getNextY(float y);
#ifndef OFXMSAGUI_DONT_USE_XML
	ofxXmlSettings					XML;
#endif
	string							xmlFilename;
};
