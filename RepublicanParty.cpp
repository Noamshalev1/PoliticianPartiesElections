#include "RepublicanPolitician.h"

RepublicanPolitician::RepublicanPolitician(): Politician(){}
RepublicanPolitician::RepublicanPolitician(const string& first, const string& last, int id, int power): Politician(first, last, id, power){} // with party
RepublicanPolitician::~RepublicanPolitician()= default;
