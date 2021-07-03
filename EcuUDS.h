//
// Created by berkeyvx on 3.07.2021.
//

#ifndef IQMINE_ECUUDS_H
#define IQMINE_ECUUDS_H

#include "Ecu.h"
#include <cstdint>
#include <vector>
#include <iostream>

class EcuUDS: public Ecu
{
private:
    std::uint16_t readDID = 0x22;

public:
    explicit EcuUDS(std::uint_fast32_t ecu_id);
    ~EcuUDS() override = default;

    std::vector<std::int16_t> ReadDataByIdentifier(std::int16_t = 0x22) const;
};


#endif //IQMINE_ECUUDS_H
