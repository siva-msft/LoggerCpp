/*
MIT License

Copyright(c) 2020 Sayantan Roy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

If you contribute to this file please add your name to the contributors list below.

Author		 : Sayantan Roy
Contributors :
*/

/* Log level
	none  = 0,
	all   = 1,
	trace = 2,
	debug = 3,
	info  = 4,
	warn  = 5,
	fatal = 6,
	error = 7
*/

#pragma once
#ifndef LGF_LOGIFY_H
#define LGF_LOGIFY_H

#include "levelUtils_lgf.h"
#include "logifyBuilder_lgf.h"
#include "staticBase_lgf.h"
#include "sourceInfo_lgf.h"

#define LVL(x) Lgfypp::Level::##x

#define Log(...) GET_MACRO(__VA_ARGS__, LOGIFY1, LOGIFY2,...) (__VA_ARGS__)
#define GET_MACRO(_1, _2, NAME, ...) NAME

#define LOGIFY1(message)            LGF::LogBuilder::logOnlyMsg(LGF::SourceInfo::current(__FILENAME__,__FUNCTION__,__LINE__,true),message)
#define LOGIFY2(format,...)         LGF::LogBuilder::logWithLevel(LGF::SourceInfo::current(__FILENAME__,__FUNCTION__,__LINE__,true),LVL(all), format, __VA_ARGS__)


#define Logify(level,format, ...)   LGF::LogBuilder::logWithLevel(LGF::SourceInfo::current(__FILENAME__,__FUNCTION__,__LINE__,true),LVL(level), format, __VA_ARGS__)

#define LogD(format,...)		    Logify(debug, format, __VA_ARGS__)
#define LogE(format,...)		    Logify(error, format, __VA_ARGS__)
#define LogW(format,...)		    Logify(warn , format, __VA_ARGS__)
#define LogI(format,...)		    Logify(info , format, __VA_ARGS__)
#define LogT(format,...)		    Logify(trace, format, __VA_ARGS__)
#define LogF(format,...)		    Logify(fatal, format, __VA_ARGS__)

#define printf(...)					Log(__VA_ARGS__)

#endif

