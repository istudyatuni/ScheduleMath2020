#include "criteria.h"

Criteria calculation;

double criterion(int crit, int place, Shedule* shed) {
    if (place == calculation.last_criterion_number) {
        return calculation.criteria_value[crit];
    }
    // заранее посчитаем критерии для определённой линии
    calculation.criteria_value[0] = calculation.overlap_lessons(shed, place); // 1st
    calculation.criteria_value[1] = calculation.bad_time(shed, place); // 2nd
    calculation.last_criterion_number = place;
    return calculation.criteria_value[crit];
}

double Criteria::overlap_lessons(Shedule* shed, int l) {
    int x = l / 5 + 1, y = l % 5 + 1;
    if (shed->m_shedule[x][y] == "") {
        return 1;
    } else {
        return 0;
    }
}

double Criteria::bad_time(Shedule* shed, int l) {
    int y = l % 5 + 1;
    if (y == 4) {
        return 1;
    }
    return 0;
}