#ifndef CRITERIA_H
#define CRITERIA_H

#include "shedule.h"

double criterion(int, int, Shedule*);

class Criteria {
public:
    int last_criterion_number = 0;// последнее место в расписании для которого мы считали критерии
    double criteria_value[number_of_criteria];

    double overlap_lessons(Shedule*);

    friend double criterion(int, int, Shedule*);
};

#endif // CRITERIA_H
