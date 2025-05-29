#include "Pirate.h"


Pirate::Pirate(const string& name, const int& bounty): name(name), Bounty(bounty) {}



void Pirate::setName(const string& name){
    this->name = name;
}


std::string Pirate::getName(){
    return name;
}

void Pirate::setBounty(const int& bounty){
    this->Bounty = bounty;
}
int Pirate::getBounty() const{
    return Bounty;
}



std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << "," << pirate.Bounty;
    return os;
}