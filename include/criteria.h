#ifndef CRITERIA_H
#define CRITERIA_H

#include "shedule.h"

double criterion(int, int, int, string, Shedule*);

class Criteria {
    int last_criterion_number = 0;// последнее место в расписании для которого мы считали критерии
    double criteria_value[number_of_criteria];

public:
    // criteria:
    double overlap_lessons(Shedule*, int);
    double audience_equipment(Shedule*, int, string);
    double bad_time(int);

    friend double criterion(int, int, int, string, Shedule*);
};

#endif // CRITERIA_H
