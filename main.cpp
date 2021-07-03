#include <iostream>
#include "EcuUDS.h"
#include "EcuKWP.h"
#include "Parser.h"

enum class ecu_type
{
    UDS,
    KWP,
};

std::vector<std::uint16_t> sendRequest(std::uint_fast16_t const ecuID, std::vector<std::int16_t> const &reqByte)
{
    auto resp = std::vector<std::uint16_t>(3);


     Parser p;
     auto f = p.parse(filename);
     readEcuParameters(ecuID, ecuType, did)


    return resp;
}

void readEcuParameters(std::uint_fast16_t ecuID,
                       ecu_type ecuType,
                       std::vector<std::uint16_t> did)
{
    EcuUDS uds(1);
    EcuKWP kwp(2);
    switch (ecuID)
    {
        case 1:
        {
            auto negRes = uds.constructNegativeResponse(0x15);
            for (auto& i: negRes)
            {
                std::cout << std::hex << i;
            }
            std::cout << "\n";
            break;
        }
        case 2:
        {
            auto negRes = kwp.constructNegativeResponse(0x15);
            for (auto& i: negRes)
            {
                std::cout << std::hex << i;
            }
            std::cout << "\n";
            break;
        }
        default:
            break;
    }
}

int main()
{
    Parser p("simulation.txt");
    auto val = p.parse();
    for (auto&i: val)
    {
        std::cout << std::hex << std::uppercase;
        std::cout << i.id << "\n";
        for (auto& ii:i.req)
        {
            std::cout << ii << " ";
        }
        std::cout << "\n";
        for (auto& ii:i.res)
        {
            std::cout << ii << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
