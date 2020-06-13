#include "shedule.h"
#include "criteria.h"

double Shedule::set_shedule() {
    int n = m_line.size();
    double quality = 0;
    for (int i = 1; i < n; ++i) {
        quality += find_good_time(i);
    }
    return quality;
}

void lost_lesson(string a, int x, int y) {
    string day;
    if (x == 1) {
        day = "Понедельник ";
    } else if (x == 2) {
        day = "Вторник ";
    } else if (x == 3) {
        day = "Среда ";
    } else if (x == 4) {
        day = "Четверг ";
    } else if (x == 5) {
        day = "Пятница ";
    }
    std::cout << day << y << " пара, lost " << a << '\n';
}

double Shedule::find_good_time(const int i) {
    double R[m_number_lessons] = { 0 };
    double maxR = 0;
    int line;//for place in shedule when maxR is right

    // 3rd and 4 formula
    map<string, string>::const_iterator aud;
    string a, req;
    for (int l = 0; l < 20; ++l) {
        // look over shedule
        for (aud = audience.begin(); aud != audience.end(); aud++) {
            // look over audience
            req = aud->second;
            a = aud->first;
            // std::cout << l << ' ' << a << ' ' << req << ' ' << m_line[i][3] << '\n';
            if (req != m_line[i][3]) {
                continue; // compare requirements for audience and lesson
                // 2nd criterion
            }
            for (int j = 0; j < number_of_criteria; ++j) {
                // look over criteria
                // criterion number j for l-line in shedule
                R[l] += weight[j] * criterion(j, l, this);
                // if print below worked, quality is changed
                //std::cout << i << ' ' << l << '.' << j << '\n';
            }
        }
        if (R[l] > maxR) {
            maxR = R[l];
            line = l;
        } else if (l == 0) {
            maxR = R[l];
            line = l;
        }
    }
    int x = line / 5 + 1, y = line % 5 + 1;
    if (m_shedule[x][y] == "") {
        m_shedule[x][y] = a + ' ' + m_line[i][0];
    } else {
        lost_lesson(m_line[i][0], x, y);
    }
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
    //Table::print();
    std::cout << "\n\t\tРасписание\n";
    char en = '\n';
    for (int i = 1; i < 6; ++i) {
        std::cout << en << m_shedule[i][0] << en;
        for (int j = 1; j < 5; ++j) {
            std::cout << m_shedule[0][j] << ": " << m_shedule[i][j] << en;
        }
    }
}