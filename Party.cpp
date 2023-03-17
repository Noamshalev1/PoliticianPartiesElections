/* Party that has a vector with the politicians
 * head of party
 * notify function that update every politician at the new head of party */
#include "Party.h"
#include "Politician.h"
#include <iostream>


/* Default constructor */
Party::Party(){}

/* Constructor for create a new party */
Party::Party(const string& name)
{
    m_name = name;
    _headOfparty = nullptr;
}
/* Update every politician in the head of party */
void Party::notifyNewheadOfparty()
{
    for(auto it = begin (politicians); it != end(politicians); ++it)
        (*it)->updateHeadOfParty();
}

/* Add a new politician to list */
void Party::addPolitician(Politician* newPolitician)
{
    if(newPolitician != nullptr) {
        politicians.push_back(newPolitician);
        newPolitician->updateParty(this); // update the head of party
    }


}
/* Remove a politician from party */
void Party::removePolitician(Politician* politician)
{
    if(politician != nullptr) {
        for(auto it = begin (politicians); it != end(politicians); ++it)
        {
            if(*(*it)==*politician) // compare between politicians
            {
                if(_headOfparty != nullptr && (*(*it))==(*_headOfparty))
                {
                    _headOfparty = nullptr;
                    notifyNewheadOfparty();
                }
                (*it)->updateParty(nullptr);
                politicians.erase(it);
                break;
            }
        }
    }

}

/* Return the head of the party */
Politician* Party::getHeadOfParty()const
{
    return _headOfparty;
}
/* Return the politician vector */
vector<Politician*> Party::getPoliticians()const {
    return politicians;
}
/* Return the name of party */
string Party::getName() const {
    return m_name;
}

/* Destroy the party */
Party::~Party() {
    politicians.clear();
}
/* Return the size of party */
int Party::getSize() const
{
    int size = politicians.size();
    return size;
}
/* Calculate and return the power of the hole party */
int Party::calculatePower()
{
    int sumOfPower = 0;
    for(auto it = begin (politicians); it != end(politicians); ++it)
        sumOfPower += (*it)->getElectionsPower();
    return sumOfPower;
}
/* Choose a new leader to be a chairman of the party */
void Party::primaries()
{
    int maxPower = -1;
    vector<Politician*>::iterator it;
    for(it = politicians.begin(); it != politicians.end(); ++it)
    {
        if((*it)->getPower() == (*it)->getElectionsPower()) // choose the leader
        {
            if((*it)->getPower() > maxPower)
            {
                maxPower = (*it)->getPower();
                _headOfparty = (*it);
            }
        }
    }
    if(maxPower == -1)
        _headOfparty = nullptr;
    else
        cout<<_headOfparty->getFirstname()<<" is the chairman of "<<m_name<<endl;
    notifyNewheadOfparty(); // update the politicians in the new header
}
