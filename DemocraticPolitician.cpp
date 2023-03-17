#include "DemocraticPolitician.h"

DemocraticPolitician::DemocraticPolitician(): Politician(){}
DemocraticPolitician::DemocraticPolitician(const string& first, const string& last, int id, int power): Politician(first, last, id, power){}
DemocraticPolitician::~DemocraticPolitician()= default;
