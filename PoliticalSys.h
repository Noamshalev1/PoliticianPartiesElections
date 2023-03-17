/* Politician system class
 * In this class we run the system and all the methods we need.
 * We will save all the politicians, parties, and some more vectors for help */
#ifndef POLITICALSYS_H
#define POLITICALSYS_H
#include "DemocraticParty.h"
#include "DemocraticLeader.h"
#include "DemocraticSocial.h"
#include "RepublicanParty.h"
#include "RepublicanLeader.h"
#include "RepublicanSocial.h"

class PoliticalSys {

    vector<Politician*> politicians; // vector for all politicians in system
    vector<Party*> parties; // vector for all parties in system
    vector<Party*> sortedParties; // same, but a sorted one (using functor)

public:
    PoliticalSys(); // default constructor
    PoliticalSys(char*); // constructor for the configuration file
    ~PoliticalSys(); // destructor (also for exit option)
    void addPolitician(); // function add a new politician to system
    void addParty(); // function add a new party to system
    void removePolitician(); // remove a politician from system
    void removeParty(); // remove a party from system
    void primaries(); // choose the strongest politician in every party
    void elections(); // calculate the power of every party and choose the winner
    void printPoliticians(); // print the politicians in system from the first to last
    void printParties(); // print the parties in system from the first to last
    void BiggestParty(); // return the biggest party --- O(1)



};


#endif //POLITICALSYS_H
