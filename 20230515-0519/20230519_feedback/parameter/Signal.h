#ifndef TAS_COMMON_PARAMETER_SIGNAL_H_
#define TAS_COMMON_PARAMETER_SIGNAL_H_

#include <set>
#include <map>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

#include "../TasDef.h"
#include "Time.h"
#include "Traffic.h"

namespace tas
{
namespace param
{

/* Ring */
enum class Ring {NONE = -1, A = 0, B = 1};
enum class RingType {NONE = 0, SINGLE = 1, DUAL = 2};

TAS_EXPORTS std::string 	toString(const Ring& ring);
TAS_EXPORTS Ring 			toRing(const std::string& text);
TAS_EXPORTS std::string 	toString(const RingType& ring);
TAS_EXPORTS RingType 	toRingType(const std::string& text);

/* Phase */
using PhaseIndex = std::uint8_t;
using PhaseType = std::uint16_t;

/**	 CycleInfo
 *         					v PhasePair
 *  ring A -> phase 			phase 			phase
 *  ring B -> phase 			phase 			phase
 */
struct TAS_EXPORTS Phase
{
	Direction start = Direction::NONE;
	Flow flow = Flow::NONE;
	std::uint8_t time = 0;

	std::map<PhaseResult, double> phaseResult;

	Phase() = default;
	Phase(const Direction& start, const Flow& end, const std::uint8_t& time = 0);

	int pattern() const;
	bool empty() const;
	void clear();
	PhaseType type() const;
	std::string description() const;

	double& operator[](const PhaseResult& result);
	bool operator==(const Phase& comp) const;
	bool operator!=(const Phase& comp) const;
};

TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const Phase& phase);

struct TAS_EXPORTS Cycle
{
	std::map<Ring, std::vector<Phase> > phases;
	std::map<Ring, std::size_t> indexs;

	tas::param::TimePoint changedCycleTime;
	tas::param::TimePoint changedPhaseTime;

	RingType ringType = RingType::NONE;

	Cycle();

	Phase phase(const Ring& ring = Ring::A, const std::uint8_t& index = 0) const;
	std::uint8_t index(const Ring& ring = Ring::A) const;
	std::uint8_t size(const Ring& ring = Ring::A) const;
	std::uint8_t cycle(const Ring& ring = Ring::A) const;
	bool empty() const;
	void clear();

	Light getLight(const tas::param::Direction& direction) const;
	std::string description() const;
	bool operator==(const Cycle& comp) const;
	bool operator!=(const Cycle& comp) const;
};

struct TAS_EXPORTS PersonPhase
{
	std::map<Direction, Light> signal;

	std::uint8_t curTime = 0;
	std::uint8_t totTime = 0;
	TimePoint timepoint;

	std::uint8_t remining() const;
	bool empty() const;
	void clear();
	std::string description() const;

	const Light& operator[](const Direction& dir) const;
	Light& operator[](const Direction& dir);
	bool operator==(const PersonPhase& comp) const;
	bool operator!=(const PersonPhase& comp) const;
};

TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const PersonPhase& object);

struct TAS_EXPORTS PersonCycle
{
	std::vector<PersonPhase> phases;
	std::uint8_t curIndex = 0;

	PersonCycle(const std::vector<PersonPhase>& phases = std::vector<PersonPhase>());

	std::uint8_t next();
	const PersonPhase& currentPhase() const;
	bool isInvalidIndex() const;
	bool isEnding() const;
	std::uint8_t size() const;
	std::uint8_t cycle() const;
	bool empty() const;
	void clear();
	std::string description() const;

	void update(const PersonCycle& person_cycle);

	const PersonPhase& operator[](const PhaseIndex& index) const;
	PersonPhase& operator[](const PhaseIndex& index);
	bool operator==(const PersonCycle& comp) const;
	bool operator!=(const PersonCycle& comp) const;
};

TAS_EXPORTS std::ostream& operator<<(std::ostream& os, const PersonCycle& object);

// std::map<PhaseResult, double> phaseResult;

} // namespace param
} // namespace tas


#endif /* TAS_COMMON_PARAMETER_SIGNAL_H_ */
