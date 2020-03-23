#pragma once

#include <chrono>
#include <sstream>      // std::stringstream
#include <iomanip>

#include "staticBase.h"
#include "lgfcore.h"

LGF_CONSTEXPR TIME_FORMAT = "%F %T";
LGF_CONSTEXPR TIME_FORMAT_ALT = "%D %T";
LGF_CONSTEXPR TIME_FORMAT_SHORT = "%T";

LGF_CONSTEXPR DEF_TIMEFORMAT = TIME_FORMAT;

LGF_BEGIN

enum class TIMEFORMAT { STANDARD, SHORT, ALTERNATIVE };
class lgftime : StaticBase
{
	static TIMEFORMAT format ;
	static std::string getTimestamp(Lgfypp::TIMEFORMAT format);
public:
	static void setTimeFormat(TIMEFORMAT value);
	static std::string getTimestamp();
	static void write_date_time(char* buff, size_t buff_size);
};

LGF_END