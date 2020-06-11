#include "shedule.h"

void Shedule::set_shedule() {
    int n = m_line.size();
    for (int i = 1; i < n; ++i) {
        find_good_time(i);
    }
}

void Shedule::find_good_time(int i) {
    int n = m_line.size();
    for (int j = 1; j < n; ++j) {

    }



    //here we must get R[i] and place l in the shedule for i lesson
}

Shedule::Shedule():Table(){
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

    for (int i = 0; i < number_of_criteria; ++i) {
        weight[i] = 1;
    }

    set_shedule();
    //print();
}

void Shedule::print() {
    Table::print();
    std::cout << "\n\t\tРасписание\n";
    char en = '\n';
    for (int i = 1; i < 6; ++i) {
        std::cout << m_shedule[i][0] << en;
        for (int j = 1; j < 5; ++j) {
            std::cout << m_shedule[0][j] << ": " << m_shedule[i][j] << en;
        }
    }
}