/* Republican social politician:
 * Can add only to a Republican party */
#ifndef CPP_NEW_REPUBLICANSOCIAL_H
#define CPP_NEW_REPUBLICANSOCIAL_H
#include "RepublicanPolitician.h"

class RepublicanSocial : public RepublicanPolitician{
public:
    RepublicanSocial();
    RepublicanSocial(const string& first, const string& last, int id, int power);
    virtual ~RepublicanSocial();
    virtual int getElectionsPower()const; // different from leader
    virtual int getPower()const; // different from leader
    void printPolitician()const;
};


#endif //CPP_NEW_REPUBLICANSOCIAL_H
