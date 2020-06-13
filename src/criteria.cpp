#include "criteria.h"

Criteria calculation;

double criterion(int crit, int place, Shedule* shed) {
    if (crit == calculation.last_criterion_number) {
        return calculation.criteria_value[crit];
    }
    // заранее посчитаем критерии для определённой линии
    calculation.criteria_value[0] = calculation.overlap_lessons(); // 1st
    calculation.last_criterion_number = place;
    return calculation.criteria_value[crit];
}

double Criteria::overlap_lessons() {
    return 1;
}