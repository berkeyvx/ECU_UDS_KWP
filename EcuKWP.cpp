//
// Created by berkeyvx on 3.07.2021.
//

#include "EcuKWP.h"
#include <iostream>

EcuKWP::EcuKWP(std::uint_fast32_t ecu_id): Ecu(ecu_id)
{
}

void EcuKWP::test()
{
    std::cout << std::hex << EcuKWP::nrc::firstByte << EcuKWP::nrc::lastByte << "\n";
}

std::vector<std::int16_t> EcuKWP::readDataByIdentifier()
{
    return std::vector<std::int16_t>();
}
