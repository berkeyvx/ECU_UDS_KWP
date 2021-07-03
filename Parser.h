//
// Created by berkeyvx on 3.07.2021.
//

#ifndef IQMINE_PARSER_H
#define IQMINE_PARSER_H

#include <cstdint>
#include <vector>
#include <string>

struct sim
{
   std::uint32_t id;
   std::vector<std::int16_t> req;
   std::vector<std::int16_t> res;
};

class Parser
{
public:
    explicit Parser(std::string &&file_name);
    std::vector<sim> parse() const;
    std::vector<std::string> splitBySpace(std::string&) const;

private:
    std::string const file_name_;
};


#endif //IQMINE_PARSER_H
