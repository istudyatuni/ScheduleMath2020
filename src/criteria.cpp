#include "criteria.h"

Criteria calculation;

double criterion(int crit, int place, int i, string aud_requirement, Shedule* shed) {
    if (place == calculation.last_criterion_number) {
        return calculation.criteria_value[crit];
    }
    // заранее посчитаем критерии для определённой линии
    calculation.criteria_value[0] = calculation.overlap_lessons(shed, place); // 1st
    calculation.criteria_value[1] = calculation.audience_equipment(shed, i, aud_requirement); // 2nd
    calculation.criteria_value[2] = calculation.bad_time(place); // 3rd
    calculation.last_criterion_number = place;
    return calculation.criteria_value[crit];
}

double Criteria::overlap_lessons(Shedule* shed, int l) {
    int x = l / 5 + 1, y = l % 5 + 1;
    return (shed->m_shedule[x][y] == "");
}

double Criteria::audience_equipment(Shedule* shed, int i, string aud_req) {
    // aud_req == m_line[i][3]
    if (shed->m_line[i][3] == "Спортзал") {
        return aud_req == shed->m_line[i][3];
    }
    return 0;
}

double Criteria::bad_time(int l) {
    int y = l % 5 + 1;
    return y == 4;
}