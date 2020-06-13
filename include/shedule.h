#ifndef SHEDULE_H
#define SHEDULE_H

#include "table.h"
#include "criteria.h"

class Shedule : private Table
{
    string m_shedule[6][5];
/*  0               1    2    3    4    5
0   время         | пн | вт | ср | чт | пт
1   9:45 - 11:10    0    4
2   11:30 - 13:05   1    5
3   13:15 - 14:50   2    6
4   15:00 - 16:35   3    7 ... - places

    вывод по дням, внутри дня - по парам:

    Пн
    1 пара: ...
    2 пара: ...

    Вт
    1 пара: ...
*/

    double weight[number_of_criteria];//весовые коэффиценты для критериев оценки качества расположения занятий

    double set_shedule(); // aka calculate
    double find_good_time(const int);
public:
    Shedule();
    void print();

    friend class Criteria;
};

#endif // SHEDULE_H
