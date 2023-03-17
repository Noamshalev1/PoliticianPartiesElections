/* Politician class implementations */
#include "Politician.h"

/* Default constructor. Initialized fields */
Politician::Politician()
{
    _firstName = "";
    _lastName = "";
    _id = 0;
    _party = nullptr;
    _headOfParty = nullptr;
    _power = 0;
}

/* Constructor with details about the politician */
Politician::Politician(const string& first, const string& last, int id, int power)
{
    _firstName = first;
    _lastName = last;
    _id = id;
    _party = nullptr; // for the meantime he just added to system
    _headOfParty = nullptr;
    _power = power;

}
/* Default destructor */
Politician::~Politician(){
}
/* Update the head of the current party of the politician  */
void Politician::updateHeadOfParty()
{
    _headOfParty = _party->getHeadOfParty();
}
/* Update a new party for the politician (and also the head)
 * if we just remove his party, we put null */
void Politician::updateParty(Party* pParty)
{
    _party = pParty;
    if(_party != nullptr)
        updateHeadOfParty();
    else
        _headOfParty = nullptr;
}
/* Compare between 2 politicians by the id (uniq) */
bool Politician::operator==(const Politician & other) const
{
    return (_id == other._id);
}
/* Return the power of the politician -
 * For social politician its different so implemented at his class */
int Politician::getElectionsPower() const{
    return _power;
}
/* Return the original power of the politician */
int Politician::getPower() const{
    return _power;
}
/* Return the politician's id */
int Politician::getId() const{
    return _id;
}
/* Return the politician's first name */
const string& Politician::getFirstname() const {
    return _firstName;
}
/* Return if the politician has a party */
bool Politician::isExistParty() {
    if(_party == nullptr)
        return false;
    return true;
}
/* Return the size of the politician's party (guessing there is) */
int Politician::getPartySize() const {
    return _party->getSize();
}
/* Return a pointer to the politician's party */
Party* Politician::getParty() const {
    return _party;
}
