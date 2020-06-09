#include <iostream>
#include <iomanip>
#include <fstream>
#include "table.h"
using namespace std;

int Table::count_suitable_audience(int i) {
    map<string, string>::iterator it = audience.begin();
    int a = 0;
    for (;it != audience.end(); it++) {
        if (it->second == m_line[i][3]) {
            a++;
        }
    }
    return a;
}

double Table::count_lessons_teacher(int i) {
    string a = m_line[i][2];
    map<string, int>::iterator tch = teachers.begin();
    for (;tch != teachers.end(); tch++) {
        if (tch->first == a) {
            return tch->second;
        }
    }
    return 0;
}

void Table::freedom_location() {
    double a, p, g = 18;
    // т.к g - количество занятий в неделю у заданной группы, а группа одна
    int s = m_line.size();
    for (int i = 1; i < s; i++) {
        a = count_suitable_audience(i);
        p = count_lessons_teacher(i);
        freedom[i] = a / (p * g);
    }
}

void Table::read_data() {     
    ifstream file("input/lessons.txt");
    string a;
    if (!file.is_open()) {
        cerr << 1 << " file isn't open";
        exit(1);
    }
    for (int i = 1; !file.eof(); ++i) {
        getline(file, a);
        m_line[i][0] = a;

        getline(file, a);
        m_line[i][1] = a;

        getline(file, a);
        m_line[i][2] = a;

        getline(file, a);
        m_line[i][3] = a;

        getline(file, a);//skip empty line
    }
    file.close();
    file.open("input/audience.txt");
    if (!file.is_open()) {
        cerr << 2 << " file isn't open";
        exit(1);
    }
    while(!file.eof()) {
        string i;
        getline(file, i);
        getline(file, a);
        audience[i] = a;
    }
    file.close();
    file.open("input/teachers.txt");
    if (!file.is_open()) {
        cerr << 3 << " file isn't open";
        exit(1);
    }
    while(!file.eof()) {
        getline(file, a);
        string i;
        getline(file, i);
        //int i;
        //file >> i; don't work correctly
        teachers[a] = stoi(i);
    }
    file.close();
}

void Table::print_line(int i) {
    map<int, string>::iterator it;
    int j = 0;
    for (it = m_line[i].begin(); it != m_line[i].end(); ++it) {
        string a = it->second;
        int width = 24 - (a.size() - a.size() / 2);;
        if (j != 0 && j != 2 && j != 4) {
            width -= 10;
        }
        if (i == 0) {
            cout.fill('_');
        }
        cout << setw(width) << left << '\t' << a;
        j++;
    }
    if (i != 0) {
        cout << setw(15) << right << freedom[i];
    }
    cout << '\n';
    cout.fill(' ');
}

Table::Table() {
    m_line.resize(19);//5 days 4 lessons and table header
    //но фактически 18 пар на неделе
    m_line[0][0] = "Название";
    m_line[0][1] = "Тип";
    m_line[0][2] = "Имя преподавателя";
    m_line[0][3] = "\tДоп требования";
    m_line[0][4] = "Свобода расположения";
    read_data();
    freedom_location();
    print();
}

void Table::print() {
    int s = m_line.size();
    for (int i = 0; i < s; i++) {
        print_line(i);
    }
    cout << "\naudience  | requirements\n";
    map<string, string>::iterator ad = audience.begin();
    for (;ad != audience.end(); ad++) {
        cout << setw(12) << left;
        cout << ad->first << ad->second << '\n';
    }
    cout << "\nСколько пар в неделю ведет каждый учитель:\n";
    map<string, int>::iterator tch = teachers.begin();
    for (;tch != teachers.end(); tch++) {
        cout << setw(4) << left << tch->second << tch->first << '\n';
    }
}