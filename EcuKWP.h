//
// Created by berkeyvx on 3.07.2021.
//

#ifndef IQMINE_ECUKWP_H
#define IQMINE_ECUKWP_H

#include "Ecu.h"
#include <vector>

class EcuKWP: public Ecu
{
private:
    static std::int16_t const readDID;
    std::int16_t did_ = -1;

public:
    explicit EcuKWP(std::uint32_t ecu_id);
    ~EcuKWP() override = default;
    void setDataIdentifier(std::vector<std::int16_t> const &did);

    std::vector<std::int16_t> ReadDataByLocalIdentifier(std::int16_t const& identifier = readDID);
};


#endif //IQMINE_ECUKWP_H
