/* A class that inheritance from Republican politician
 * There is only one function implemented here: print the politician */
#include "RepublicanLeader.h"

RepublicanLeader::RepublicanLeader(): RepublicanPolitician(){}
RepublicanLeader::RepublicanLeader(const string& first, const string& last, int id, int power) : RepublicanPolitician(first, last, id, power){}
RepublicanLeader::~RepublicanLeader()= default;
void RepublicanLeader::printPolitician()const
{
    if(_headOfParty == nullptr)
        cout<<"Republican Person:"<<_firstName<<" "<<_lastName<<", Id:"<<_id<<", Power:"<<_power<<", Type:L, Chairman: None"<<endl;
    else
        cout<<"Republican Person:"<<_firstName<<" "<<_lastName<<", Id:"<<_id<<", Power:"<<_power<<", Type:L, Chairman: "<<_headOfParty->getFirstname()<<endl;
}
