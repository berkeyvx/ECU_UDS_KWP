#include <iostream>
#include "EcuUDS.h"
#include "EcuKWP.h"
#include "Parser.h"

enum class ecu_type
{
    UDS,
    KWP,
};

void readEcuParameters(std::uint_fast16_t ecuID,
                       ecu_type ecuType,
                       std::vector<std::int16_t> const& did);

std::vector<std::int16_t> sendRequest(std::uint_fast16_t const ecuID, std::vector<std::int16_t> const &reqByte)
{
    EcuUDS ecu1(1);
    EcuKWP ecu2(2);

    if(ecuID == 1)
    {
        ecu1.setDataIdentifier(reqByte);
        return ecu1.ReadDataByIdentifier();
    }
    else if(ecuID == 2)
    {
        ecu2.setDataIdentifier(reqByte);
        return ecu2.ReadDataByLocalIdentifier();

    }
    else
    {
        throw std::invalid_argument("ECU NOT SUPPORTED YET");
    }
    return {};
}

void readEcuParameters(std::uint_fast16_t ecuID,
                       ecu_type ecuType,
                       std::vector<std::int16_t> const& did)
{
    if (ecuType == ecu_type::UDS)
    {
        if (did.size() != 2)
            return;
        auto resp = sendRequest(ecuID, did);
        for (auto& res: resp)
        {
            std::cout << std::hex << std::uppercase << res << " ";
        }
        std::cout << "\n";

    }
    else if (ecuType == ecu_type::KWP)
    {
        if(did.size() != 1)
            return;
        auto resp = sendRequest(ecuID, did);
        for (auto& res: resp)
        {
            std::cout << std::hex << std::uppercase << res << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    readEcuParameters(1, ecu_type::UDS, {0x12,0x35}); // should return response
    readEcuParameters(1, ecu_type::UDS, {0x12,0x36}); // should fail
    readEcuParameters(2, ecu_type::KWP, {0x12}); // should return response
    readEcuParameters(2, ecu_type::KWP, {0x13}); // should fail
    readEcuParameters(3,ecu_type::UDS, {0x11, 0x14}); // should throw invalid_argument
    return 0;
}
