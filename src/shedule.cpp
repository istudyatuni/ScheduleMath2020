#include "shedule.h"

double Shedule::set_shedule() {
    int n = m_line.size();
    double quality = 0;
    for (int i = 1; i < n; ++i) {
        quality += find_good_time(i);
    }
    return quality;
}

double Shedule::find_good_time(const int i) {
    double R[m_number_lessons] = { 0 };
    double maxR = 0;
    int line;//for place in shedule when maxR is right

    // 3rd and 4 formula
    for (int l = 0; l < 20; ++l) {
        //R[l] = w[j] * k[j][l]
        for (int j = 0; j < number_of_criteria; ++j) {
            //criterion number j for l-line in shedule
            R[l] += weight[j] * criterion(j, l);
        }
        if (R[l] > maxR) {
            maxR = R[l];
            line = l;
        } else if (l == 0) {
            maxR = R[l];
            line = l;
        }
    }
    m_shedule[line / 5 + 1][line % 5 + 1] = m_line[i][0];
    return maxR;
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

    double qu = set_shedule();
    print();
    std::cout << "\nShedule quality is " << qu;
}

void Shedule::print() {
    Table::print();
    std::cout << "\n\t\tРасписание\n";
    char en = '\n';
    for (int i = 1; i < 6; ++i) {
        std::cout << en << m_shedule[i][0] << en;
        for (int j = 1; j < 5; ++j) {
            std::cout << m_shedule[0][j] << ": " << m_shedule[i][j] << en;
        }
    }
}