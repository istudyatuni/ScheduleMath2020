#include "shedule.h"

void Shedule::find_good_time() {
    int n = m_line.size();
    for (int i = 1; i < n; ++i) {

    }
}
void Shedule::print() {
    Table::print();
    std::cout << "\nShedule:\n";
    char en = '\n';
    for (int i = 1; i < 6; ++i) {
        std::cout << m_shedule[i][0] << en;
        for (int j = 1; j < 5; ++j) {
            std::cout << m_shedule[0][j] << ": " << m_shedule[i][j] << en;
        }
    }
}