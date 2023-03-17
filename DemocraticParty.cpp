/* All the functions here are not implemented in Party
 * except from constructors/destructor
 * The only function implemented here is print */
#include "DemocraticParty.h"
#include <iostream>
DemocraticParty::DemocraticParty(): Party(){}
DemocraticParty::DemocraticParty(const string& name): Party(name){}
DemocraticParty::~DemocraticParty()= default;
/* check if the politician fits this party */
bool DemocraticParty::canJoinParty(Politician* p)
{
    return p->canJoinDemocratParty();
}
/* This function print the party and it's politicians */
void DemocraticParty::printParty()
{
    if(_headOfparty == nullptr) // if head is null print None
        cout<<"Democrat Party: "<<m_name<<", chairman:None, Size:"<<politicians.size()<<endl;
    else
        cout<<"Democrat Party: "<<m_name<<", chairman:"<<_headOfparty->getFirstname()<<", Size:"<<politicians.size()<<endl;
    for(auto it = begin (politicians); it != end(politicians); ++it) // print the politicians
    {
        cout<<"\t";
        (*it)->printPolitician();
    }


}
