#pragma once

#include "ofTypes.h"
#include "ofPoint.h"

class ofxSimpleGuiConfig {
public:
	ofPoint	gridSize;

	float	buttonHeight;
	float	toggleHeight;
	float	sliderHeight;
	float	sliderTextHeight;
	float	slider2DTextHeight;
	float	titleHeight;
	float	comboBoxHeight;
	float	comboBoxTextHeight;

	ofPoint padding;
	ofPoint offset;
	ofPoint	slider2DSize;

	int	textColor;
	int textOverColor;
	int textBGColor;
	int textBGOverColor;

	int fullColor;
	int	fullOverColor;
	int fullActiveColor;
	int emptyColor;
	int borderColor;

	ofxSimpleGuiConfig();
};


extern ofxSimpleGuiConfig defaultSimpleGuiConfig;

