/* This class inheritance from Party*/
#ifndef CPP_NEW_REPUBLICANPARTY_H
#define CPP_NEW_REPUBLICANPARTY_H
#include "Party.h"
#include "RepublicanPolitician.h"
class RepublicanParty: public Party {
public:
    // there are more functions implemented in Party class
    RepublicanParty(); // default constructor
    RepublicanParty(const string& name);
    virtual ~RepublicanParty(); // must be virtual
    virtual void printParty(); // pure virtual in Party
    bool canJoinParty(Politician*);
};


#endif //CPP_NEW_REPUBLICANPARTY_H
