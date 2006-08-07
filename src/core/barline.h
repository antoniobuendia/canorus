/** @file barline.h
 * 
 * Copyright (c) 2006, Matevž Jekovec, Canorus development team
 * All Rights Reserved. See AUTHORS for a complete list of authors.
 * 
 * Licensed under the GNU GENERAL PUBLIC LICENSE. See COPYING for details.
 */

#ifndef BARLINE_H_
#define BARLINE_H_

#include "core/muselement.h"

class CAStaff;

class CABarline : public CAMusElement{
	public:
		enum CABarlineType {
			Single,
			Double,
			End,
			RepeatOpen,
			RepeatClose,
			Dotted
		};
		
		CABarline(CABarlineType type, CAStaff *staff, int startTime);
		
		CABarlineType barlineType() { return _barlineType; }
		
		virtual ~CABarline();
	
	private:
		CABarlineType _barlineType;
};

#endif /*BARLINE_H_*/
