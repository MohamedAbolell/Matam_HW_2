#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int Bounty;

public:

    explicit Pirate(const string& name = "", const int& bounty = 0);

    ~Pirate() = default;

    void setName(const string& name);

    void setBounty(const int& bounty);

    int getBounty() const;

    string getName();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};