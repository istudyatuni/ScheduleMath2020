#ifndef SHEDULE_H
#define SHEDULE_H

#include "table.h"

class Shedule : public Table
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

    void find_good_time(); // aka calculate
public:
    Shedule():Table(){
        m_shedule[0][0] = "";
        m_shedule[0][1] = "9:45 - 11:10";
        m_shedule[0][2] = "11:30 - 13:05";
        m_shedule[0][3] = "13:15 - 14:50";
        m_shedule[0][4] = "15:00 - 16:35";

        m_shedule[1][0] = "Понедельник";
        m_shedule[2][0] = "Вторник";
        m_shedule[3][0] = "Среда";
        m_shedule[4][0] = "Четверг";
        m_shedule[5][0] = "Пятница";
        find_good_time();
        print();
    }
    void print();
};

#endif // SHEDULE_H
