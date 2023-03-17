/* A class that inheritance from Republican politician
 * There is only 2 functions implemented here: return the elections power, and print the politician */
#include "RepublicanSocial.h"

RepublicanSocial::RepublicanSocial(): RepublicanPolitician(){}
RepublicanSocial::RepublicanSocial(const string& first, const string& last, int id, int power) : RepublicanPolitician(first, last, id, power){}
RepublicanSocial::~RepublicanSocial()= default;

int RepublicanSocial::getPower() const
{
    // this is for primaries
    return -1;
}
int RepublicanSocial::getElectionsPower()const
{
    return 2*_power;
}
void RepublicanSocial::printPolitician()const
{
    if(_headOfParty == nullptr)
        cout<<"Republican Person:"<<_firstName<<" "<<_lastName<<", Id:"<<_id<<", Power:"<<_power<<", Type:S, Chairman: None"<<endl;
    else
        cout<<"Republican Person:"<<_firstName<<" "<<_lastName<<", Id:"<<_id<<", Power:"<<_power<<", Type:S, Chairman: "<<_headOfParty->getFirstname()<<endl;
}
