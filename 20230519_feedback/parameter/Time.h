#ifndef TAS_COMMON_PARAMETER_TIME_H_
#define TAS_COMMON_PARAMETER_TIME_H_

#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include "../TasDef.h"

namespace tas
{
namespace param
{

using TimeTable = std::tm;
using TimeCount = std::uint8_t;
using TimeSerial = std::int64_t;
using TimePoint = std::chrono::system_clock::time_point;

// get Current std::timepoint
TAS_EXPORTS TimePoint 	currentTimepoint();
TAS_EXPORTS TimeTable 	timePoint2timeTable(const TimePoint& time_point);
TAS_EXPORTS TimeSerial 	timePointSerializeMsec(const TimePoint& time_point);
TAS_EXPORTS std::string 	toString(const TimePoint& time_point,
		const bool& include_date = true,
		const bool& include_time = true,
		const bool& include_msec = true);
TAS_EXPORTS time_t str2time_t(const std::string& dateStr, const char& dateDiv = '-', const char& timeDiv = ':');
TAS_EXPORTS TimePoint time_t2TimePoint(const time_t& tT);
TAS_EXPORTS TimePoint str2TimePoint(const std::string& dateStr, const char& dateDiv = '-', const char& timeDiv = ':');

} // namespace param
} // namespace tas

#endif /* TAS_COMMON_PARAMETER_TIME_H_ */