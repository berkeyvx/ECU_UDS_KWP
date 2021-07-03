//
// Created by berkeyvx on 3.07.2021.
//

#ifndef IQMINE_ECU_H
#define IQMINE_ECU_H

#include <cstdint>
#include <array>

class Ecu
{
private:
    std::uint_fast32_t const ecu_id_;

protected:
    struct negative_response_constants{
        static std::int16_t const firstByte = 0x7F;
        static std::int16_t const lastByte = 0x31;
    };
    using nrc = negative_response_constants;

public:
    std::array<std::int16_t, 3> constructNegativeResponse(std::uint16_t middleByte);

public:
    explicit Ecu(std::uint_fast32_t ecu_id);
    virtual ~Ecu() = 0;
    std::uint_fast32_t getEcuId() const;
};


#endif //IQMINE_ECU_H
