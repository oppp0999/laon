#ifndef TAS_COMMON_PARAMETER_TRAFFIC_H_
#define TAS_COMMON_PARAMETER_TRAFFIC_H_

#include <set>
#include <string>
#include <chrono>
#include <cstdlib>

#include "../TasDef.h"

namespace tas
{
namespace param
{

using GroupID				= std::uint16_t;
using InterID 			= std::uint16_t;
using AvenueID 			= std::uint16_t;
using ChannelID			= std::uint16_t;

/* Common */
constexpr auto LANE_NULL = 0;
constexpr auto NOT_SET_VALUE = -1;
constexpr auto NOT_SET_VALUE_UNSIGNED = 0;

using LaneID 			= int;
using Volume 			= std::uint16_t;
using AvenueIndex 	= std::uint16_t;
using Occupancy 		= double;
using Distance 			= double;
using Speed 				= double;
using SaturationRate 	= double;
using Time 				= float;

enum class PhaseResult {NONE = 0x00, INIT_WAIT_LENGTH, MAX_WAIT_LENGTH, AVG_SPEED, OCCUPANCY, VOLUME, TEMP_1, TEMP_2};
TAS_EXPORTS std::string 		toString(const PhaseResult& flow, const bool& is_initial = false);

enum class Flow {NONE = 0x00, RIGHT = 0x01, STRAIGHT = 0x02, LEFT = 0x03, UTURN = 0x04};
using Flows = std::set<Flow>;

TAS_EXPORTS std::string 		toString(const Flow& flow);
TAS_EXPORTS Flow				toFlow(const std::string& text);

enum class Passes {NONE = 0x00, FORWARD = 0x01, BACKWARD = 0x02};
using LaneCountingFlows = std::set<Passes>;

TAS_EXPORTS std::string 		toString(const Passes& lane_counting_flow);
TAS_EXPORTS Passes	toLaneCountingFlow(const std::string& text);

enum class LaneType {NONE = 0x0000, RIGHT = 0x0001, STRAIGHT = 0x0002, LEFT = 0x0004,
	UTURN = 0x0008, VARIABLE = 0x0010, BUS = 0x0020, EXIT = 0x0040, SHOULDER = 0x0080};
using LaneTypes = std::set<LaneType>;

TAS_EXPORTS std::string 		toString(const LaneType& lane_type);
TAS_EXPORTS LaneType			toLaneType(const std::string& text);

enum class Direction {NONE = 0x00, NORTH, EAST, SOUTH, WEST, NORTH_EAST, SOUTH_EAST, NORTH_WEST, SOUTH_WEST};

TAS_EXPORTS std::string 		toString(const Direction& direction, const bool& initial = false);
TAS_EXPORTS Direction		toDirection(const std::string& text);

enum class Light {NONE = 0x00, RED, GREEN, GREEN_FLASH, FLASH, LEFT, GREEN_LEFT, YELLOW, TEMP};

TAS_EXPORTS std::string 		toString(const Light& light);
TAS_EXPORTS Light 			toLight(const std::string& text);

enum class VehicleViolation {NONE = 0x00, BUSLANE, LANE, STOPLINE, TAILGATING, SIGNAL_VEHICLE, CENTER_LINE, REVERSE,
	SHOULDER_STOP, SHOULDER_RUN, ILLEGAL_U_TURN, PARKING, ACCIDENT, SPILLBACK, SIDEWALK, SIGNAL_MOTORCYCLE};

TAS_EXPORTS std::string 		toString(const VehicleViolation& vehicle_violation_type);
TAS_EXPORTS VehicleViolation toVehicleViolation(const std::string& text);

enum class PersonViolation {NONE = 0x00, ROAD, SIGNAL, ACCIDENT};

TAS_EXPORTS std::string 		toString(const PersonViolation& person_violation_type);
TAS_EXPORTS PersonViolation toPersonViolation(const std::string& text);

enum class ObjectLocation {NONE = 0x00, LANE, ROAD, CROSSWALK, WALKWAY_WAIT, WALKWAY_DETECT, WALKWAY_DANGER};

TAS_EXPORTS std::string 		toString(const ObjectLocation& object_location);
TAS_EXPORTS ObjectLocation  toObjectLocation(const std::string& text);

enum class ObjectType {NONE = 0x00, PEDESTRIAN, VEHICLE, SMALL_TRUCK, LARGE_TRUCK,
	SMALL_BUS, LARGE_BUS, MOTORCYCLE, AMBULANCE,
	POLICE_CAR, SPECIAL_CAR, WHEEL_CHAIR, SMART_MOBLITY};

TAS_EXPORTS std::string 		toString(const ObjectType& object_type);
TAS_EXPORTS ObjectType  		toObjectType(const std::string& text);

enum class AvenuePosition {NONE = 0X00, ONE, NEAR, FAR, UNDER, OVER};

TAS_EXPORTS std::string 		toString(const AvenuePosition& avenue_position);
TAS_EXPORTS AvenuePosition		toAvenuePosition(const std::string& position);

} // namespace param
} // namespace tas

#endif /* TAS_COMMON_PARAMETER_TRAFFIC_H_ */
