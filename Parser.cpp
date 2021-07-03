//
// Created by berkeyvx on 3.07.2021.
//

#include "Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

Parser::Parser(std::string &&file_name):file_name_(file_name)
{
}

std::vector<sim> Parser::parse() const
{
    std::ifstream file(file_name_);
    std::string id, req, res;
    std::vector<sim> ret;
    while(!file.eof())
    {
        sim mock;
        std::getline(file,id);
        if(id.empty() || id == "\r" || id == "\n")
            continue;
        if(id[id.size() - 1] == '\r')
        {
            id.pop_back();
        }
        std::getline(file, req);
        if(req[req.size() - 1] == '\r')
        {
            req.pop_back();
        }
        std::getline(file, res);
        if(res[res.size() - 1] == '\r')
        {
            res.pop_back();
        }
        auto id_ = splitBySpace(id);
        mock.id = std::stoi(id_[1]);
        auto req_ = splitBySpace(req);
        std::transform(req_.begin() + 1, req_.end(), std::inserter(mock.req, mock.req.begin()),
                       [](std::string& t){return std::stoi(t, nullptr, 16);});
        auto resp_ = splitBySpace(res);
        std::transform(resp_.begin() + 1, resp_.end(), std::inserter(mock.res, mock.res.begin()),
                       [](std::string& t){return std::stoi(t, nullptr, 16);});
        ret.push_back(mock);
    }
    return ret;
}

std::vector<std::string> Parser::splitBySpace(std::string &str) const
{
    char const space_delimiter = ' ';
    std::vector<std::string> words{};

    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, space_delimiter)) {
        words.push_back(s);
    }
    return words;
}
