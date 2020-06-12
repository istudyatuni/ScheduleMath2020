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
        freedom[i - 1] = a / (p * g);
    }
    //maybe replace this call
    sort_by_freedom();
}

void Table::read_data() {     
    string a = "input/lessons.txt";
    ifstream file(a);
    if (!file.is_open()) {
        cerr << a << " file isn't open";
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
    }
    file.close();
    a = "input/audience.txt";
    file.open(a);
    if (!file.is_open()) {
        cerr << a << " file isn't open";
        exit(1);
    }
    while(!file.eof()) {
        string i;
        getline(file, i);
        getline(file, a);
        audience[i] = a;
    }
    file.close();
    a = "input/teachers.txt";
    file.open(a);
    if (!file.is_open()) {
        cerr << a << " file isn't open";
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
        cout << setw(20) << right << freedom[i - 1];
    }
    cout << '\n';
    cout.fill(' ');
}

void Table::sort_by_freedom() {
    // bubble
    //in freedom indexing from 0,
    //but in m_line from 1
    int n = freedom.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (freedom[j] > freedom[j + 1]) {
                swap(freedom[j], freedom[j + 1]);
                swap(m_line[j + 1], m_line[j + 2]);
            }
        }
    }
}

Table::Table() {
    m_number_lessons = 18;
    m_line.resize(m_number_lessons + 1);//5 days 4 lessons and table header
    //но фактически 18 пар на неделе
    m_line[0][0] = "Название";
    m_line[0][1] = "Тип";
    m_line[0][2] = "Имя преподавателя";
    m_line[0][3] = "\tДоп требования";
    m_line[0][4] = "Свобода расположения";
    read_data();
    freedom_location();
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