/* A class that inheritance from Democrat politician */
#ifndef CPP_NEW_DEMOCRATICSOCIAL_H
#define CPP_NEW_DEMOCRATICSOCIAL_H
#include "DemocraticPolitician.h"

class DemocraticSocial : public DemocraticPolitician{
    // the fileds taken from Democratic politician
public:
    DemocraticSocial();
    DemocraticSocial(const string& first, const string& last, int id, int power);
    virtual ~DemocraticSocial(); // must be virtual
    virtual int getElectionsPower()const; // different from leader
    virtual int getPower()const; // different from leader
    virtual void printPolitician()const; // pure virtual in Politician
};


#endif //CPP_NEW_DEMOCRATICSOCIAL_H
