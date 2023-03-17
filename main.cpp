//============================================================================
// Name        : politicalSystem.cpp
// Author      : ADP 23
// Version     : 0.0.0
// Copyright   : Your copyright notice
// Description : Assignment 5 in C++, Ansi-style
//============================================================================
#include "PoliticalSys.h"
#include <exception>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {

    PoliticalSys* politicalSys = new PoliticalSys(argv[1]);
    char menuOption ='a';
    while(menuOption!='0')
    {

        cout<< "1. Add Politician" << endl;
        cout<< "2. Add Party" << endl;
        cout<< "3. Remove Politician" << endl;
        cout<< "4. Remove Party" << endl;
        cout<< "5. Elections" << endl;
        cout<< "6. Print Politicians" << endl;
        cout<< "7. Print Parties" << endl;
        cout<< "8. Biggest Party" << endl;
        cout<< "0. Exit" << endl;
        cin >> menuOption;
        switch(menuOption){
            case '1': // there is "new" so we need to check for any bad alloc
                try
                {
                    politicalSys->addPolitician();
                }
                catch(exception& e)
                {
                    delete politicalSys;
                    return 0;
                }
                break;
            case '2': // there is "new" so we need to check for any bad alloc
                try
                {
                    politicalSys->addParty();
                }
                catch(exception& e)
                {
                    delete politicalSys;
                    return 0;
                }
                break;
            case '3':
                try
                {
                    politicalSys->removePolitician();
                }
                catch(exception& e)
                {
                    delete politicalSys;
                    return 0;
                }
                break;
            case '4':
                try
                {
                    politicalSys->removeParty();
                }
                catch(exception& e)
                {
                    delete politicalSys;
                    return 0;
                }
                break;
            case '5':
                politicalSys->elections();
                break;
            case '6':
                politicalSys->printPoliticians();
                break;
            case '7':
                politicalSys->printParties();
                break;
            case '8':
                politicalSys->BiggestParty();
                break;
            case '0':
                delete politicalSys;
                break;
        }
    }

    return 0;
}
