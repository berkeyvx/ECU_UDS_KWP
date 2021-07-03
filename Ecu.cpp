//
// Created by berkeyvx on 3.07.2021.
//

#include "Ecu.h"

Ecu::~Ecu()
= default;

inline
std::uint_fast32_t Ecu::getEcuId() const
{
    return ecu_id_;
}

Ecu::Ecu(std::uint_fast32_t ecu_id): ecu_id_(ecu_id)
{
}

std::array<std::int16_t, 3> Ecu::constructNegativeResponse(std::uint16_t middleByte)
{
    return std::array<std::int16_t, 3>{Ecu::nrc::firstByte, static_cast<std::int16_t>(middleByte), Ecu::nrc::lastByte};
}
