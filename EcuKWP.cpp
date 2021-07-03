//
// Created by berkeyvx on 3.07.2021.
//

#include "EcuKWP.h"


std::int16_t const EcuKWP::readDID = 0x21;

EcuKWP::EcuKWP(std::uint32_t ecu_id): Ecu(ecu_id)
{
}

std::vector<std::int16_t> EcuKWP::ReadDataByLocalIdentifier(std::int16_t const& identifier)
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
            if(*reqIter == did_)
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

void EcuKWP::setDataIdentifier(std::vector<std::int16_t> const & did)
{
    did_ = did[0];
}
