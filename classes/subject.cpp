#include <iostream>
#include "subject.h"
using namespace std;

void subject::print() {
    cout << "\n* * " << name << ":\n";
    cout << num << " pair in week\n";
    cout << stype << endl;
    cout << "tutor ID: " << tId << "\n";
}

void subject::input(int i){
    cout << "\nsubject " << i + 1 << ":\nenter name:";
    //cin >> name;
    name = 'a' + i;//to_string(i);
    num = rand() % 4 + 1;
    cout << "number pair in week: " << num;
    cout << "\nsubject type (practic, lection): ";
    int c = rand() % 2;
    if (c == 0)
        stype = "lection";
    else if (c == 1)
        stype = "practic";
    cout << stype;
    tId = i;
    cout << "\ntId: " << tId;
    cout << '\n';
}