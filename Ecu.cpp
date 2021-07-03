//
// Created by berkeyvx on 3.07.2021.
//

#include "Ecu.h"

Ecu::~Ecu()
= default;

std::uint32_t Ecu::getEcuId() const
{
    return ecu_id_;
}

Ecu::Ecu(std::uint32_t ecu_id): ecu_id_(ecu_id)
{
}

std::vector<std::int16_t> Ecu::constructNegativeResponse(std::int16_t middleByte) const
{
    return std::vector<std::int16_t>{Ecu::nrc::firstByte, middleByte, Ecu::nrc::lastByte};
}
