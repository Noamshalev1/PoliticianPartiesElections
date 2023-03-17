/* Politician System implementations */
#include "PoliticalSys.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstring>
using namespace std;

/* 3 kinds of exceptions
 * IdException - when the user enter a wrong id
 * NameException - when the user enter a wrong name
 * DataException - when the user enter wrong details
 * Every class inheritance from exception */

class IdException : public exception{
    virtual const char* what() const throw()
    {
        return "Please enter valid id";
    }
};
class NameException : public exception{
    virtual const char* what() const throw()
    {
        return "Please enter valid name";
    }
};
class DataException : public exception{
    virtual const char* what() const throw()
    {
        return "Please enter valid details";
    }
};

/* A functor:
 * Compare between 2 parties
 * First by size then by length name
 * Used for sorted vector */
class bigger_than{
public:
    bool operator()(const Party* p1, const Party* p2)
    {
        if(p1->getSize() > p2->getSize())
            return true;
        else if(p2->getSize() > p1->getSize())
            return false;
        else
        {
            if(strcmp(p1->getName().c_str(), p2->getName().c_str()) > 0)
                return true;
            return false;
        }
    }
};

/* Default constructor */
PoliticalSys::PoliticalSys( )= default;

/* Read from file constructor:
 * First enter all the politicians (without parties)
 * Than add the parties and insert politicians to them
 * There was also use in try and catch for exceptions */
PoliticalSys::PoliticalSys(char* path) {

    std::ifstream file(path);
    string line, first, last, lean, type, name;
    int id, power;
    Politician* newPolitician = nullptr;
    getline(file,line); // ignore the "Politicians:" line
    while(getline(file,line))
    {
        istringstream buf(line); // keep the line we read from
        if(line == "Parties:\r") // a sigh we need to change our loop
            break;
        buf>>first>>last>>id>>power>>lean>>type;
        /* Choose where the politician should be */
        if(lean == "R" && type == "L")
            newPolitician = new RepublicanLeader(first, last, id, power);
        else if(lean == "R" && type == "S")
            newPolitician = new RepublicanSocial(first, last, id, power);
        else if(lean == "D" && type == "L")
            newPolitician = new DemocraticLeader(first, last, id, power);
        else if(lean == "D" && type == "S")
            newPolitician = new DemocraticSocial(first, last, id, power);
        /* Add the new politician to vector */
        politicians.push_back(newPolitician);

    }
    Party* newParty;
    Party* tmp;
    /* This loop is for parties, after done with politicians */
    while(getline(file,line))
    {
        istringstream buf(line);
        buf>>name>>lean;
        /* Create new party and add politicians to the new party */
        if(lean == "R")
            newParty = new RepublicanParty(name);
        else
            newParty = new DemocraticParty(name);
        for(auto it = begin (politicians); it != end(politicians); ++it)
        {
            if(newParty->canJoinParty(*it))
            {
                /* By the conditions - if the politician has no party,
                * or the party he belongs to is bigger than the new one */
                if(!(*it)->isExistParty() || (*it)->getPartySize() > newParty->getSize())
                {
                    if((*it)->isExistParty())
                    {
                        tmp = (*it)->getParty();
                        tmp->removePolitician((*it));

                    }
                    newParty->addPolitician((*it));
                }
            }
        }
        parties.push_back(newParty);
        sortedParties.push_back(newParty);
        /* Sort the parties by the functor */
        std::sort(sortedParties.begin(), sortedParties.end(), bigger_than());
    }
    file.close();


}

/* function that add a politician to system.
 * then, we add him to party */
void PoliticalSys::addPolitician()
{
    string first, last, lean, type;
    int id, power;
    cout<<"---Create Politician---"<<endl;
    while(true)
    {
        cout<<"First name:"<<endl;
        cin>>first;
        cout<<"Last name:"<<endl;
        cin>>last;
        cout<<"ID:"<<endl;
        cin>>id;
        cout<<"Power:"<<endl;
        cin>>power;
        cout<<"Republican or Democratic person"<<endl;
        cin>>lean;
        cout<<"Leader or Social"<<endl;
        cin>>type;
        try
        {
            if(power < 0 || id < 0 || (lean != "R" && lean != "D") || (type != "L" && type != "S"))
                throw DataException(); // Exception thrown here because we want to continue
            if(!politicians.empty())
            {
                for(auto it = begin (politicians); it != end(politicians); ++it)
                {
                    if((*it)->getId() == id)
                        throw DataException();
                }
            }
        }
        catch(exception& e)
        {
            cerr<<e.what()<<endl;
            continue;
        }
        /* After we check the details, we can continue */
        break;
    }
    Politician* newPolitician = nullptr;
    /* Choose where the politician should be */
    if(lean == "R" && type == "L")
        newPolitician = new RepublicanLeader(first, last, id, power);
    else if(lean == "R" && type == "S")
        newPolitician = new RepublicanSocial(first, last, id, power);
    else if(lean == "D" && type == "L")
        newPolitician = new DemocraticLeader(first, last, id, power);
    else if(lean == "D" && type == "S")
        newPolitician = new DemocraticSocial(first, last, id, power);
    /* Push the new politician to the vector */
    politicians.push_back(newPolitician);
    /* Then add him to the correct party */
    Party* pParty;
    // at first, add the new politician to the oldest party
    for(auto it = begin (parties); it != end(parties); ++it)
    {
        if((*it)->canJoinParty(newPolitician))
        {
            (*it)->addPolitician(newPolitician);
            break;
        }
    }
    // then stat checking for the smallest
    for(auto it = begin (parties); it != end(parties); ++it)
    {
        pParty = newPolitician->getParty();
        if((*it)->canJoinParty(newPolitician))
        {
            if(newPolitician->getPartySize() > (*it)->getSize())
            {
                pParty->removePolitician(newPolitician);
                (*it)->addPolitician(newPolitician);
            }
        }
    }
    /* Sort again */
    if(!sortedParties.empty())
        std::sort(sortedParties.begin(), sortedParties.end(), bigger_than());

}

/* Add a new party to system */
void PoliticalSys::addParty()
{
    string name, lean;
    cout<<"---Create Party---"<<endl;
    while(true)
    {
        cout<<"Name:"<<endl;
        cin>>name;
        cout<<"Republican or Democratic party"<<endl;
        cin>>lean;
        try
        {
            if(lean != "R" && lean != "D")
                throw DataException();
            for(auto it = begin (parties); it != end(parties); ++it)
            {
                if(name == (*it)->getName())
                    throw DataException();
            }
        }
        catch(exception& e)
        {
            cerr<<e.what()<<endl;
            continue;
        }
        break;
    }
    Party* newParty;
    Party* tmp;
    /* Create new party and add politicians to the new party */
    if(lean == "R")
        newParty = new RepublicanParty(name);
    else
        newParty = new DemocraticParty(name);
    for(auto it = begin (politicians); it != end(politicians); ++it)
    {
        /* Same conditions as before */
        if((newParty)->canJoinParty(*it))
        {
            if(!(*it)->isExistParty() || (*it)->getPartySize() > newParty->getSize())
            {
                if((*it)->isExistParty())
                {
                    tmp = (*it)->getParty();
                    tmp->removePolitician((*it));

                }
                newParty->addPolitician((*it));
            }
        }
    }
    parties.push_back(newParty);
    sortedParties.push_back(newParty);
    /* Sort again */
    std::sort(sortedParties.begin(), sortedParties.end(), bigger_than());
}

/* Remove a politician from system
 * First remove him from party
 * Then remove him total */
void PoliticalSys::removePolitician()
{
    int id;
    Politician* pPolitician;
    Party* pParty;
    bool check;
    if(!politicians.empty())
    {
        cout<<"---Remove Politician---"<<endl;
        while(true)
        {
            check = false;
            cout<<"Enter the ID:"<<endl;
            cin>>id;
            try
            {
                if(id < 0)
                    throw IdException();
                for(auto it = begin (politicians); it != end(politicians); ++it)
                {
                    if ((*it)->getId() == id)
                    {
                        check = true;
                        pPolitician = (*it);
                        politicians.erase(it);
                        break;
                    }
                }
                if(!check)
                    throw IdException();
            }
            catch(exception& e)
            {
                cerr<<e.what()<<endl;
                continue;
            }
            break;
        }
        /* Get the party the politician belong to.
        * Remove it from the party and update it's party to null */
        pParty = pPolitician->getParty();
        pParty->removePolitician(pPolitician);
        delete pPolitician;
        /* If there are parties, sort again! */
        if(!sortedParties.empty())
            std::sort(sortedParties.begin(), sortedParties.end(), bigger_than());
    }
}

/* Remove a party from system
 * All the politicians in the party go search for a new one
 * If no one fit to them there weren't belong to anyone. */
void PoliticalSys::removeParty()
{
    if(!parties.empty())
    {
        bool check;
        vector<Politician*> tmpPoliticians;
        Party* toDelete;
        string name;
        cout<<"---Remove Party---"<<endl;
        while(true)
        {
            check = false;
            cout<<"Enter party name:"<<endl;
            cin>>name;
            for(auto it = begin (parties); it != end(parties); ++it)
            {
                if((*it)->getName() == name)
                {
                    check = true;
                    tmpPoliticians = (*it)->getPoliticians(); // get the politicians
                    toDelete = (*it); // keep the party to remove later
                    parties.erase(it); // remove the pointer only
                    break;
                }
            }
            try
            {
                if(!check)
                    throw NameException();
            }
            catch(exception& e)
            {
                cerr<<e.what()<<endl;
                continue;
            }
            break;
        }
        /* After found it, go and erase the pointer from parties vector */
        for(auto it = begin (parties); it != end(parties); ++it)
        {
            if(toDelete->getName() == (*it)->getName())
            {
                parties.erase(it);
                break;
            }
        }
        /* Also from the sorted one */
        for(auto it = begin (sortedParties); it != end(sortedParties); ++it)
        {
            if(toDelete->getName() == (*it)->getName())
            {
                sortedParties.erase(it);
                break;
            }

        }
        /* finally delete the party from system */
        delete toDelete;
        /* Move on the politicians that in the party and start to add them to new parties */
        Party* ptParty;
        int min;
        if(!tmpPoliticians.empty())
        {
            /* first loop run on politicians */
            for(auto it = begin (tmpPoliticians); it != end(tmpPoliticians); ++it)
            {
                if(!parties.empty()) // if there is any party fit to them
                {
                    // at first, add the politician to the oldest party
                    for(auto p = begin (parties); p != end(parties); ++p)
                    {
                        if((*p)->canJoinParty(*it))
                        {
                            (*p)->addPolitician(*it);
                            break;
                        }
                    }
                    /* Now search for the smallest */
                    for(auto p = begin (parties); p != end(parties); ++p)
                    {
                        ptParty = (*it)->getParty();
                        if((*p)->canJoinParty(*it))
                        {
                            if ((*it)->getPartySize() > (*p)->getSize())
                            {
                                ptParty->removePolitician(*it);
                                (*p)->addPolitician(*it);
                            }
                        }
                    }
                }
                else
                    (*it)->updateParty(nullptr); // the politicians have no party
            }
        }
    }
    /* If there are parties, sort again */
    if(!sortedParties.empty())
        std::sort(sortedParties.begin(), sortedParties.end(), bigger_than());

}
/* Every party choose her chairman */
void PoliticalSys::primaries()
{
    if(!parties.empty() && !politicians.empty())
    {
        cout<<"----Primaries----"<<endl;
        vector<Party*>::iterator it;
        for(it =parties.begin(); it != parties.end(); ++it)
            (*(*it)).primaries();
    }
}
void PoliticalSys::elections()
{
    primaries();
    int max_power = -1;
    int power;
    Party* winner;
    if(!parties.empty() && !politicians.empty())
    {
        cout<<"----Elections----"<<endl;
        for(auto it = begin (parties); it != end(parties); ++it)
        {
            power = (*it)->calculatePower();
            if(max_power < power)
            {
                max_power = power;
                winner = (*it);
            }
            cout<<"Party: "<<(*it)->getName()<<",Power: "<<power<<endl;
        }
        cout<<"----Elections Results----"<<endl;
        if(winner->getHeadOfParty() != nullptr)
            cout<<winner->getName()<<" party won the elections and "<<(winner->getHeadOfParty())->getFirstname()<<" is the prime minister"<<endl;
        else
            cout<<winner->getName()<<" party won the elections and None is the prime minister"<<endl;
    }

}
/* Print all politicians in system */
void PoliticalSys::printPoliticians()
{
    if(!politicians.empty())
    {
        cout<<"----Politicians----"<<endl;
        for(auto it = begin (politicians); it != end(politicians); ++it)
            (*it)->printPolitician();
    }
}
/* Print all parties in system */
void PoliticalSys::printParties()
{
    if(!parties.empty())
    {
        cout<<"----Parties----"<<endl;
        for(auto it = begin (parties); it != end(parties); ++it)
            (*it)->printParty();
    }
}
/* Return the biggest party from sorted vector */
void PoliticalSys::BiggestParty()
{
    if(!sortedParties.empty())
    {
        cout<<"----Biggest Party----"<<endl;
        cout<<"["<<(*(sortedParties.begin()))->getName()<<","<<(*(sortedParties.begin()))->getSize()<<"]"<<endl;
    }
}
/* Destroy the system */
PoliticalSys::~PoliticalSys()
{
    sortedParties.clear();
    vector<Party*>::iterator it;
    for(it =parties.begin(); it != parties.end(); ++it)
        delete (*it);
    parties.clear();
    vector<Politician*>::iterator p;
    for(p =politicians.begin(); p != politicians.end(); ++p)
        delete (*p);
    politicians.clear();
}
