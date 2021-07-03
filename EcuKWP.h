//
// Created by berkeyvx on 3.07.2021.
//

#ifndef IQMINE_ECUKWP_H
#define IQMINE_ECUKWP_H

#include "Ecu.h"
#include <vector>

class EcuKWP: public Ecu
{
public:
    explicit EcuKWP(std::uint_fast32_t ecu_id);
    ~EcuKWP() override = default;
    void test();

    std::vector<std::int16_t> readDataByIdentifier();
};


#endif //IQMINE_ECUKWP_H
