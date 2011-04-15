/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2003 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/**
 * @file logging.h
 * Logging definitions.
 * @author The GemRB Project
 */


#ifndef LOGGING_H
#define LOGGING_H

#include "exports.h"
#include "win32def.h"

#ifdef ANDROID
#	include <android/log.h>
#endif

#ifdef WIN32
#	define ADV_TEXT
#	include <conio.h>
extern GEM_EXPORT HANDLE hConsole;
#else //WIN32
#	ifndef ANDROID
#		include <config.h>
#	endif
#	include <cstdio>
#	include <cstdlib>
#endif //WIN32

enum log_color {
	DEFAULT,
	BLACK,
	RED,
	GREEN,
	BROWN,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	LIGHT_RED,
	LIGHT_GREEN,
	YELLOW,
	LIGHT_BLUE,
	LIGHT_MAGENTA,
	LIGHT_CYAN,
	LIGHT_WHITE
};

#ifndef ANDROID
#	define printBracket(status, color) textcolor(WHITE); print("["); textcolor(color); print("%s", status); textcolor(WHITE); print("]")
#	define printStatus(status, color) printBracket(status, color); print("\n")
#	define printMessage(owner, message, color) printBracket(owner, LIGHT_WHITE); print(": "); textcolor(color); print("%s", message)
#else
#	define printBracket(status, color)
#	define printStatus(status, color) __android_log_print(ANDROID_LOG_INFO, "GemRB", "[%s]", status)
#	define printMessage(owner, message, color) __android_log_print(ANDROID_LOG_INFO, "GemRB", "%s: %s", owner, message)
#endif

GEM_EXPORT void print(const char* message, ...);
GEM_EXPORT void textcolor(log_color);

#if (__GNUC__ > 4)
// poison printf
extern "C" int printf(const char* message, ...) __attribute__ ((deprecated))
#endif

#endif
