/** @file drawablenote.h
 * 
 * Copyright (c) 2006, Matevž Jekovec, Canorus development team
 * All Rights Reserved. See AUTHORS for a complete list of authors.
 * 
 * Licensed under the GNU GENERAL PUBLIC LICENSE. See COPYING for details.
 */

#ifndef DRAWABLENOTE_H_
#define DRAWABLENOTE_H_

#include "drawable.h"

class CANote;

class CADrawableNote : public CADrawable {
	public:
		CADrawableNote(CANote *note, int x, int y);
		void draw(QPainter *p, CADrawSettings s);
	
	private:
		CANote *_note;	
};

#endif /*DRAWABLENOTE_H_*/