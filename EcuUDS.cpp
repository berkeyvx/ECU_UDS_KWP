//
// Created by berkeyvx on 3.07.2021.
//

#include "EcuUDS.h"
#include <iostream>

std::int16_t const EcuUDS::readDID = 0x22;

std::vector<std::int16_t> EcuUDS::ReadDataByIdentifier(std::int16_t const& identifier) const
{
    auto parsedData = parser.parse();
    auto present = false;
    auto saveIter = parsedData.begin();
    for (auto iter = parsedData.begin(); iter != parsedData.end(); iter++)
    {
        if(iter->id != Ecu::getEcuId())
            continue;
        for(auto reqIter = iter->req.begin(); reqIter != iter->req.end(); reqIter++)
        {
            if(*reqIter == did0_ && std::next(reqIter) != iter->req.end() && *std::next(reqIter) == did1_)
            {
                saveIter = iter;
                present = true;
                break;
            }
        }
    }
    if (!present)
        return constructNegativeResponse(readDID);

    std::vector<std::int16_t> resp{identifier};
    std::copy(saveIter->res.begin(), saveIter->res.end(), std::inserter(resp, std::end(resp)));

    return resp;
}

EcuUDS::EcuUDS(std::uint32_t ecu_id): Ecu(ecu_id)
{
}

void EcuUDS::setDataIdentifier(std::vector<std::int16_t> const &did)
{
    did0_ = did[0];
    did1_ = did[1];
}
