/* Democratic politician :
 * Can add only to a Democrat party */

#ifndef CPP_NEW_DEMOCRATICPOLITICIAN_H
#define CPP_NEW_DEMOCRATICPOLITICIAN_H
#include "Politician.h"

class DemocraticPolitician : public Politician{
public:
    DemocraticPolitician();
    DemocraticPolitician(const string& first, const string& last, int id, int power);
    virtual ~DemocraticPolitician();
    virtual bool canJoinRepublicanParty() {return false; } // cannot add
    virtual bool canJoinDemocratParty() {return true; } // can add

};


#endif //CPP_NEW_DEMOCRATICPOLITICIAN_H
