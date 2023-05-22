#ifndef TAS_COMMON_RESULT_H_
#define TAS_COMMON_RESULT_H_

#include "Signal.h"
#include "../TasDef.h"

#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <functional>

namespace tas
{
namespace param
{

enum class ChannelState {NONE, INIT, CONNECT, READY, ANALYSIS, FAIL};

TAS_EXPORTS std::string toString(const ChannelState& state);

struct TAS_EXPORTS LaneInfo
{
	std::set<LaneType> types;
	Volume totalVolume				= NOT_SET_VALUE_UNSIGNED; // #
	Volume waitVolume					= NOT_SET_VALUE_UNSIGNED; // #
	Distance totalLength				= NOT_SET_VALUE_UNSIGNED; // m
	Distance waitLength				= NOT_SET_VALUE_UNSIGNED; // m
	Distance laneLength				= NOT_SET_VALUE_UNSIGNED; // m
	Speed totalSpeed					= NOT_SET_VALUE_UNSIGNED; // km/h
	Volume speedVolume				= NOT_SET_VALUE_UNSIGNED; // #

	// TimePoint
	Time totalTime						= NOT_SET_VALUE_UNSIGNED;
	Time totalTimeOccupancyTime			= NOT_SET_VALUE_UNSIGNED;
	std::map<std::string, std::string> others;

	Occupancy timeRatio() const;
	Occupancy totalRatio() const;
	Occupancy waitRatio() const;
	Speed avgSpeed() const;

	void clear();
	bool empty() const;
	bool operator==(const LaneInfo& comp) const;
	bool operator!=(const LaneInfo& comp) const;
	std::string& operator[](const std::string& key);
	const LaneInfo operator+(const LaneInfo& lane_info) const;
	std::string description() const;
};

/* LaneInfo std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const LaneInfo& lane_info);

struct TAS_EXPORTS VehicleInfo
{
	std::uint64_t id = 0;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	double lat = 0;
	double lng = 0;
	TimePoint timePoint;
	double duration = 0;
	LaneID laneID = 0;
	ObjectType type;
	Flow flow;
	Passes passes;
	double speed = 0;
	bool isStopped = true;
	VehicleViolation vehicleViolation = VehicleViolation::NONE;

	std::map<std::string, std::string> others;

	void clear();
	bool empty() const;
	bool operator==(const VehicleInfo& comp) const;
	bool operator!=(const VehicleInfo& comp) const;
	std::string& operator[](const std::string& key);
};

struct TAS_EXPORTS AvenueState
{
	std::map<LaneID, LaneInfo> laneInfo;
	std::map<std::uint64_t, VehicleInfo> vehicleInfo;
	AvenueID avenueID						= 0;
	AvenuePosition position					= AvenuePosition::NONE;
	std::map<std::string, std::string> others;

	void clear();
	bool empty() const;
	std::size_t size() const;

	bool operator==(const AvenueState& comp) const;
	bool operator!=(const AvenueState& comp) const;
	std::string& operator[](const std::string& key);
	LaneInfo& operator[](const std::size_t& index);
	const LaneInfo operator[](const std::size_t& index) const;
	const AvenueState operator+(const AvenueState& avenue_info) const;
	const AvenueState& operator+=(const AvenueState& avenue_info);
	std::string description() const;
};

/* AvenueInfo std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const AvenueState& avenue_info);

struct TAS_EXPORTS VehicleCount
{
	std::uint64_t objectID					= 0x0000;
	TimePoint detectedTimePoint;
	TimePoint countedTimePoint;
	Direction direction						= Direction::NONE;
	AvenueID avenueID						= 0;
	LaneID laneNum							= 0;
	std::set<LaneType> laneType;
	Flow flow                               = Flow::NONE;
	Passes passes                           = Passes::NONE;
	ObjectType type							= ObjectType::NONE;
	Speed speed								= 0;
	double length							= 0;
	std::string file;
	std::string plateNumber					= std::string();
	VehicleViolation vehicleViolation	= VehicleViolation::NONE;
	std::map<std::string, std::string> others;

	bool isViolation(const VehicleViolation& violation) const;

	void clear();
	bool empty() const;
	bool operator==(const VehicleCount& comp) const;
	bool operator!=(const VehicleCount& comp) const;
	std::string& operator[](const std::string& key);
	std::string description() const;
};

/* VehicleCount std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const VehicleCount& vehicle_count);

struct TAS_EXPORTS VehicleEvent
{
	std::uint64_t objectID					= 0x0000;
	Direction direction						= Direction::NONE;
	AvenueID avenueID						= 0;
	VehicleViolation vehicleViolation		= VehicleViolation::NONE;
	ObjectType type							= ObjectType::NONE;
	std::string plateNumber					= std::string();
	TimePoint timePoint;
	std::string file;
	std::string path;
	std::map<std::string, std::string> others;

	void clear();
	bool empty() const;
	bool operator==(const VehicleEvent& comp) const;
	bool operator!=(const VehicleEvent& comp) const;
	std::string& operator[](const std::string& key);
	std::string description() const;
};

/* VehicleEvent std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const VehicleEvent& vehicle_event);

struct TAS_EXPORTS PersonInfo
{
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	double lat = 0;
	double lng = 0;
	std::uint64_t objectID					= 0x0000;
	TimePoint firstDetTime;
	Direction startDir						= Direction::NONE;
	Direction endDir							= Direction::NONE;
	AvenueID avenueID							= 0;
	ObjectLocation location					= ObjectLocation::NONE;
	double duration							= tas::param::NOT_SET_VALUE;
	PersonViolation personViolation			= PersonViolation::NONE;
	std::map<std::string, std::string> others;

	void clear();
	bool empty() const;
	bool operator==(const PersonInfo& comp) const;
	bool operator!=(const PersonInfo& comp) const;
	std::string& operator[](const std::string& key);
	std::string description() const;
};

/* PersonInfo std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const PersonInfo& person_info);

struct TAS_EXPORTS PersonCount
{
	std::uint64_t objectID					= 0x0000;
	TimePoint timePoint;
	Direction startDir						= Direction::NONE;
	Direction endDir							= Direction::NONE;
	AvenueID avenueID							= 0;
	ObjectLocation location					= ObjectLocation::NONE;
	PersonViolation personViolation			= PersonViolation::NONE;
	double duration							= 0;

	std::map<std::string, std::string> others;

	bool isViolation(const PersonViolation& type) const;

	void clear();
	bool empty() const;
	bool operator==(const PersonCount& comp) const;
	bool operator!=(const PersonCount& comp) const;
	std::string& operator[](const std::string& key);
	std::string description() const;
};

/* PersonCount std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const PersonCount& person_count);

struct TAS_EXPORTS PersonEvent
{
	std::uint64_t objectID			= 0x0000;
	Direction startDir				= Direction::NONE;
	Direction endDir					= Direction::NONE;
	AvenueID avenueID					= 0;
	PersonViolation personViolation	= PersonViolation::NONE;
	TimePoint timePoint;
	std::string file;
	std::string path;
	std::map<std::string, std::string> others;

	void clear();
	bool empty() const;
	bool operator==(const PersonEvent& comp) const;
	bool operator!=(const PersonEvent& comp) const;
	std::string& operator[](const std::string& key);
	std::string description() const;
};

/* PersonEvent std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const PersonEvent& person_event);

struct TAS_EXPORTS InterResult
{
	std::string label;

	std::map<ChannelID, ChannelState> channels;

	std::map<Direction, AvenueState> vehicleState;
	std::vector<VehicleCount> vehicleCount;
	std::vector<VehicleEvent> vehicleEvent;

	std::map<std::uint64_t, PersonInfo> personState;
	std::vector<PersonCount> personCount;
	std::vector<PersonEvent> personEvent;

	Cycle cycle;
	PersonCycle pcycle;

	Cycle prevCycle;
	PersonCycle prevPCycle;

	std::map<std::string, std::string> others;

	void clear();
	bool empty() const;
	bool operator==(const InterResult& comp) const;
	bool operator!=(const InterResult& comp) const;
	std::string& operator[](const std::string& key);
	std::string description() const;
};

TAS_EXPORTS std::string diffrenceCheck(InterResult& ret1, InterResult& ret2);

/* InterResult std::cout overloading */
TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const InterResult& event_result);

using TrafficResult = std::map<InterID, InterResult>;

using ResultHandler = std::function<bool(const TimePoint& tp, const TrafficResult& result)>;

using TrafficSignal = std::map<InterID, Cycle>;

using SignalHandler = std::function<bool(const TimePoint& tp, const TrafficSignal& cycle)>;

} // namespace param
} // namespace tas
#endif /* INCLUDE_TAS_COMMON_RESULT_H_ */
