#ifndef CRITERIA_H
#define CRITERIA_H

class Shedule;

const int number_of_criteria = 7;


double criterion(int, int, Shedule*);

class Criteria {
    int last_criterion_number = 0;// последнее место в расписании для которого мы считали критерии
    double criteria_value[number_of_criteria];

public:
    double overlap_lessons();

    friend double criterion(int, int, Shedule*);
};

#endif // CRITERIA_H
