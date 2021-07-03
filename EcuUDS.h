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
    static std::int16_t const readDID;
    std::int16_t did0_ = -1;
    std::int16_t did1_ = -1;

public:
    explicit EcuUDS(std::uint32_t ecu_id);
    ~EcuUDS() override = default;

    std::vector<std::int16_t> ReadDataByIdentifier(std::int16_t const& identifier = 0x22) const;
    void setDataIdentifier(std::vector<std::int16_t> const &);
};


#endif //IQMINE_ECUUDS_H
