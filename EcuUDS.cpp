//
// Created by berkeyvx on 3.07.2021.
//

#include "EcuUDS.h"
#include <iostream>

std::vector<std::int16_t> EcuUDS::ReadDataByIdentifier(std::int16_t identifier) const
{

    return std::vector<std::int16_t>{static_cast<std::int16_t>(readDID)};
}

EcuUDS::EcuUDS(std::uint_fast32_t ecu_id): Ecu(ecu_id)
{
}
