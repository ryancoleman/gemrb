/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2016 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "ScrollView.h"

namespace GemRB {

ScrollView::ScrollView(const Region& frame)
: View(frame), contentView(frame)
{
	hscroll = NULL;
	vscroll = NULL;
}

void ScrollView::SizeChanged(const Size&)
{

}

void ScrollView::Scroll(Size /*s*/)
{
	// TODO: implement scrolling behavior
}

bool ScrollView::OnKeyPress(unsigned char key, unsigned short /*mod*/)
{
	if (vscroll && (key == GEM_UP || key == GEM_DOWN)) {
		// TODO: get the scroll value from settings
		Scroll(Size(0, 10));
		return true;
	}
	if (vscroll && (key == GEM_RIGHT || key == GEM_LEFT)) {
		// TODO: get the scroll value from settings
		Scroll(Size(10, 0));
		return true;
	}

	return false;
}

void ScrollView::OnMouseWheelScroll(short x, short y)
{
	Scroll(Size(x, y));
}

}
