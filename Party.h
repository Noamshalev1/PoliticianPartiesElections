/* Party abstract class
 * responsible to add a new politician to list of politicians (vector)
 * remove a politician from list
 * Primaries - choose the most powerful leader politician
 * calculate powerful, and print the lean memberships */
#ifndef PARTY_H
#define PARTY_H
#include <string>
#include "vector"

using namespace std;

class Politician;

class Party{
protected:
    string m_name;
    Politician* _headOfparty;
    vector<Politician*> politicians;
    void notifyNewheadOfparty(); // a notify function - responsible to update all the politician with the new head.
public:
    Party(); // default constructor
    Party(const string& name); // constructor to create a new party
    virtual ~Party(); // destructor - must be virtual
    void addPolitician(Politician*); // add a new politician to party
    void removePolitician(Politician*); // remove a politician from the party
    Politician* getHeadOfParty()const; // return a pointer to the head of the party
    vector<Politician*> getPoliticians()const; // return the politicians
    string getName()const; // return the name of the party
    int getSize()const; // return the size of the party
    int calculatePower(); // return the power of all the politician in elections
    void primaries(); // choose a new chairman
    virtual void printParty()=0; // pure virtual for print
    virtual bool canJoinParty(Politician*)=0;





};


#endif //PARTY_H
