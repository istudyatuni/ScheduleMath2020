#ifndef SHEDULE_H
#define SHEDULE_H

#include "table.h"

class Shedule : private Table
{
    string m_shedule[6][5];
/*  0               1    2    3    4    5
0   время         | пн | вт | ср | чт | пт
1   9:45 - 11:10
2   11:30 - 13:05
3   13:15 - 14:50
4   15:00 - 16:35

    вывод по дням, внутри дня - по парам:

    Пн
    1 пара: ...
    2 пара: ...

    Вт
    1 пара: ...
*/

    static const int number_of_criteria = 7;
    double weight[number_of_criteria];//весовые коэффиценты для критериев оценки качества расположения занятий

    void set_shedule(); // aka calculate
    void find_good_time(int);
public:
    Shedule();
    void print();
};

#endif // SHEDULE_H
