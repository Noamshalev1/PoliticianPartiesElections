/* Politician class:
 * Has the details about the politician and his party (if exist)
 * This class is abstract - the print function is pure virtual!
 * All the not virtual functions implemented only in Politician.cpp */
#ifndef POLITICIAN_H
#define POLITICIAN_H
#include "Party.h"
#include <string>
#include <iostream>
using namespace std;
/* All the inherits classes have thous fields */
class Politician{
protected:
    string _firstName;
    string _lastName;
    int _id;
    Party* _party;
    Politician* _headOfParty;
    int _power;
public:
    Politician(); // default constructor
    Politician(const string& first, const string& last, int id, int power); // constructor of create new politician
    virtual ~Politician(); // destructor - must be virtual for his inherits
    void updateHeadOfParty(); // update the head of party
    void updateParty(Party* pParty); // update when the politician added to a new party
    bool operator==(const Politician&)const; // compare between 2 politician
    virtual int getElectionsPower()const; // virtual function - for social politician it's implemented in his class
    virtual int getPower()const; // get the original power of the leader politician, for social return -1
    int getId()const; // get the id of politician (for deletion option)
    bool isExistParty(); // check if the politician has a party
    int getPartySize()const; // get the size of politician party (if exist)
    Party* getParty()const; // return a pointer to the politician party
    const string& getFirstname()const; // return the politician first name (for printing the head)
    virtual void printPolitician()const=0; // pure virtual - implemented only in the inherits.
    virtual bool canJoinRepublicanParty()=0; // these functions will implement only in Republican and Democrat Politician
    virtual bool canJoinDemocratParty()=0;


};


#endif //POLITICIAN_H
