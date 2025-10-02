//
// Enum.h
//

#pragma once

#include "mq/base/Enum.h"

#include <ostream>
#include <sstream>

namespace mq {

// -----------------------------------------------------------------------------
// output as hex

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
std::ostream& operator<<(std::ostream& os, E a)
{
	using UT = std::underlying_type_t<E>;

	auto prev_fill = os.fill('0');
	auto prev_base = os.setf(std::ios_base::hex);
	auto prev_width = os.width(sizeof(UT) * 2);
	os << "0x" << static_cast<UT>(a);
	os.width(prev_width);
	os.setf(prev_base, std::ios_base::basefield);
	os.fill(prev_fill);
	return os;
}

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
std::string to_string(E a)
{
	std::stringstream ss;
	ss << a;
	return ss.str();
}

} // namespace mq
