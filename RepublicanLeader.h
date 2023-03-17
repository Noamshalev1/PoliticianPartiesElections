#ifndef CPP_NEW_REPUBLICANLEADER_H
#define CPP_NEW_REPUBLICANLEADER_H
#include "RepublicanPolitician.h"

class RepublicanLeader : public RepublicanPolitician{
public:
    RepublicanLeader();
    RepublicanLeader(const string& first, const string& last, int id, int power);
    virtual ~RepublicanLeader();
    virtual void printPolitician()const;

};


#endif //CPP_NEW_REPUBLICANLEADER_H
