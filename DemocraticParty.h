/* This class inheritance from Party*/
#ifndef CPP_NEW_DEMOCRATICPARTY_H
#define CPP_NEW_DEMOCRATICPARTY_H
#include "Party.h"
#include "DemocraticPolitician.h"
class DemocraticParty : public Party {
    // take filed from Party
public:
    // there are more functions implemented in Party class
    DemocraticParty(); // default constructor
    DemocraticParty(const string& name);
    virtual ~DemocraticParty(); // must be virtual
    virtual void printParty(); // pure virtual in Party
    bool canJoinParty(Politician*);

};


#endif //CPP_NEW_DEMOCRATICPARTY_H
