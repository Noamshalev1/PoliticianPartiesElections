/* A class that inheritance from Democrat politician
 * There is only 2 functions implemented here: print the politician and calculate his power in elections */
#include "DemocraticSocial.h"

DemocraticSocial::DemocraticSocial(): DemocraticPolitician(){}
DemocraticSocial::DemocraticSocial(const string& first, const string& last,  int id, int power) : DemocraticPolitician(first, last, id, power){} // call the constructor
DemocraticSocial::~DemocraticSocial()= default;
int DemocraticSocial::getPower() const
{
    // this is for primaries
    return -1;
}
int DemocraticSocial::getElectionsPower()const
{
    return 2*_power;
}
void DemocraticSocial::printPolitician()const
{
    if(_headOfParty == nullptr) // if head is null, we print "None"
        cout<<"Democratic Person:"<<_firstName<<" "<<_lastName<<", Id:"<<_id<<", Power:"<<_power<<", Type:S, Chairman: None"<<endl;
    else
        cout<<"Democratic Person:"<<_firstName<<" "<<_lastName<<", Id:"<<_id<<", Power:"<<_power<<", Type:S, Chairman: "<<_headOfParty->getFirstname()<<endl;
}
