//
// Created by berkeyvx on 3.07.2021.
//

#ifndef IQMINE_ECU_H
#define IQMINE_ECU_H

#include <cstdint>
#include <array>
#include "Parser.h"

namespace {
    auto constexpr file = "simulation.txt";
}

class Ecu
{
private:
    std::uint32_t const ecu_id_;

protected:
    struct negative_response_constants{
        static std::int16_t const firstByte = 0x7F;
        static std::int16_t const lastByte = 0x31;
    };
    using nrc = negative_response_constants;
    Parser parser{file};

public:
    std::vector<std::int16_t> constructNegativeResponse(std::int16_t middleByte) const;

public:
    explicit Ecu(std::uint32_t ecu_id);
    virtual ~Ecu() = 0;
    std::uint32_t getEcuId() const;
};


#endif //IQMINE_ECU_H
