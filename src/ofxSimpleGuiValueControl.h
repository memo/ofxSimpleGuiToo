#pragma once

#include "ofxSimpleGuiControl.h"

template <typename T>
class ofxSimpleGuiValueControl : public ofxSimpleGuiControl {
public:
	T	*value;
	T	oldValue;
	
	ofxSimpleGuiValueControl(string name, T &value) : ofxSimpleGuiControl(name), value(&value) {}
	
	virtual bool changed() {
		if(*value != oldValue) {
			oldValue = *value;
			return true;
		}
		return false;
	}
	
//	void update() {
//	}
};