#ifndef TAS_COMMON_PARAMETER_SYSTEMEVENT_H_
#define TAS_COMMON_PARAMETER_SYSTEMEVENT_H_

#include <string>

#include "../TasDef.h"

namespace tas
{
namespace param
{

enum class Category {NONE = 0x00, TAS = 1, CAMERA = 2, LOS = 3, REBOOT = 4};

TAS_EXPORTS std::string getDescription(const Category& category, const bool& is_connect = true);

struct NetworkStateInfo
{
	int inter_id;
	int avenue_id;
	Category category;

	bool operator<(const NetworkStateInfo& state_info) const;
};

TAS_EXPORTS std::string 		toString(const Category& category);
TAS_EXPORTS Category			toCategory(const std::string& text);

} // namespace param
} // namespace tas

#endif /* TAS_COMMON_PARAMETER_SYSTEMEVENT_H_ */
