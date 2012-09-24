#include "ofxSimpleGuiConfig.h"

ofxSimpleGuiConfig defaultSimpleGuiConfig;


ofxSimpleGuiConfig::ofxSimpleGuiConfig() {
	
	sliderHeight		= 10;
	sliderTextHeight	= 22;
	titleHeight			= sliderHeight + sliderTextHeight;
	toggleHeight		= titleHeight;
	buttonHeight		= titleHeight;
	slider2DTextHeight	= titleHeight * 1.5;
	comboBoxHeight		= titleHeight;	//15
	comboBoxTextHeight	= 15;
	
	
	padding.set			(titleHeight/2, 5);
	offset.set			(titleHeight/2, titleHeight/2);
	slider2DSize.set	(titleHeight * 4, titleHeight * 4);
	
	gridSize.x			= 200 + padding.x;
	gridSize.y			= toggleHeight + padding.y;
	
	textColor			= 0x888888;
	textOverColor		= 0xFFFFFF;
	textBGColor			= 0x000000;
	textBGOverColor		= 0x222222;
	
	fullColor			= 0xaaaaaa;
	fullOverColor		= 0xffffff;
	fullActiveColor		= 0x881818;
	emptyColor			= 0x333333;
	
	borderColor			= 0x333333;
}