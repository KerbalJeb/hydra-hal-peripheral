/// @file common.hpp
/// @brief Created on 2021-08-28 by Ben

#pragma once

namespace hh{
/// \brief A status return code
enum class status {
  success = 0,
  invalid_args,
  configuration_failed,
};

/// \brief Writes to the given bits
/// \pre All unmasked value bits must be zero (ie. value&mks == value)
/// \param reg The register
/// \param value The value to write
/// \param msk The bits to write to
inline void write_with_msk(volatile std::uint32_t& reg, std::uint32_t value, std::uint32_t msk)
{
//    assert((value&msk) == value);
    auto reg_value = reg;
    // Set bits
    reg_value |= value;
    // Clear bits
    reg_value &= ~(value ^ msk);
    reg = reg_value;
}

}