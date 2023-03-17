/* Republican politician :
 * Can add only to a Republican party */
#ifndef CPP_NEW_REPUBLICANPOLITICIAN_H
#define CPP_NEW_REPUBLICANPOLITICIAN_H
#include "Politician.h"

class RepublicanPolitician : public Politician{
public:
    RepublicanPolitician();
    RepublicanPolitician(const string& first, const string& last,  int id, int power);
    virtual ~RepublicanPolitician();
    virtual bool canJoinRepublicanParty() {return true; } // can add
    virtual bool canJoinDemocratParty() {return false; } // cannot add
};


#endif //CPP_NEW_REPUBLICANPOLITICIAN_H
