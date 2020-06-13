#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <map>
using std::map;
using std::string;

class Table {
protected:
    int m_number_lessons;//18
    std::vector<map<int, string>> m_line;
    //0 - title, 1 - type, 2 - teacher's name, 3 - requirements
    //m_line[0][i] - table header

    //sorry for using numbering from 1 (0 line is header for output)
    map<string, string> audience;//number, additional info
private:
    map<string, int> teachers;// teacher's name, number lessons
    map<int, double> freedom;//line[i], value

    int count_suitable_audience(int i);
    double count_lessons_teacher(int i);
    void freedom_location();
    void read_data();
    void print_line(int i);
    void sort_by_freedom();
public:
    Table();
    void print();
};

#endif // TABLE_H
