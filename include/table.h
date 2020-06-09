#include <iostream>
#include <vector>
#include <map>
using std::map;
using std::string;

class Table {
    std::vector<map<int, string>> m_line;
    //0 - title, 1 - type, 2 - teacher's name, 3 - requirements
    map<string, string> audience;//number, additional info
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