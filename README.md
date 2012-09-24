ofxSimpleGuiToo
=====================================

Introduction
------------
C++ openFrameworks addon for simple and very quick to setup GUI based on Todd Vanderlin's ofxSimpleGui. It uses a very similar (almost identical) API, but with a rewritten backend.

Licence
-------
The code in this repository is available under the [MIT License](https://secure.wikimedia.org/wikipedia/en/wiki/Mit_license).  
Copyright (c) 2008-2012 Memo Akten, [www.memo.tv](http://www.memo.tv)  
The Mega Super Awesome Visuals Company


Installation
------------
Copy to your openFrameworks/addons folder.

Dependencies
------------
- ofxMSAInteractiveObject
- ofxXmlSettings

Compatibility
------------
OF0072


Known issues
------------
none

Version history
------------
### v1.4    23/09/2012
- compatible with OF0072
- renamed (uppercase) MSA namespace to (lowercase) msa. (kept MSA as an alias for backwards compatibility)

### v1.3
- page::saveToXML() pushed the <controls> tag so control::saveToXML() didn't need to check that tag, 
  whereas page::loadFromXML() didn't push the <controls> tag so control::loadFromXML() did.
  Wasn't consistent so now all controls can assume that we are already inside the <controls> tag.
- fixed keyboard support (any control which the mouse is hovering over, now receives the events:
     keyPressed(int key), keyReleased(int key), onKeyUp(), onKeyDown(), onKeyLeft(), onKeyRight(), onKeyEnter()

### v1.2
- lots of thing, can't remember. whoops.

### v1.1	07/04/2009
- changed license to revised BSD (a lot more more permissive than GPL)

### v1.0
- initial version
- changes from original ofxSimpleGui
	- added pages (tabs), controls are added to pages
	- when controls reach bottom of page (customizable using page.height property) controls flow to the right
	- ability to customize spacing / sizes / colors etc. using a configuration class
	- everything on a grid
	- addFrame has been renamed to addContent and manages any class type which extends ofBaseDraws
	- saved in xml using 'keys', so you can add/remove/rename/reorder controls and still load values correctly
	- option to backup save
	- all controls inherit from ofxMSAInteractiveObject (for simpler event management)


