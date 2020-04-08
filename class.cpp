#include <iostream>
#include <cstdlib>
#include <ctime>

#include "class.h"

using std::cout, std::cin, std::endl, std::swap;

//subject

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

//functions

void sort_sub(subject a[]){//сортировка предметов по убыванию часов
    cout << "sorting . .\n";
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10 - i - 1; j++){
            if (a[j].num < a[j+1].num)
                swap(a[j], a[j+1]);
            cout << i << '.' << j << "  ";
        }
        cout << '\n';
    }
}
void print_sub(subject a[]) {
    cout << "\ntable subjects:\n";
    for (int i = 0; i < 10; i++) {
        a[i].print();
    }
    cout << endl;
}
void input_sub(subject a[]) {
    srand(time(0));
    cout << "input subjects:\n";
    for (int i = 0; i < 10; i++) {
        a[i].input(i);
    }
}

//tutor

//уже не нужен метод записи в массив из массива-параметра
void tutor::write_work (int (&a)[4][5]) {
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 5; ++j){
            work[i][j] = a[i][j];
        }
    }
}
void tutor::input_work () {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << i << '.' << j << ": ";
            cin >> work[i][j];
        }
    }
}
void tutor::print(){
    cout << "tutor " << name << ", " << post;
    cout << "\nwork:\n";
    for (int j = 0; j < 4; j++) {
        for (int h = 0; h < 5; h++)
            cout << work[j][h] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
void tutor::input(int i){
    cout << "\ntutor " << i + 1 << ":\nenter name:";
    //cin >> name;
    name = 'z' - i;
    cout << "position: ";//enter
    int c = rand() % 4;
    if (c == 0)
        post = "senior lecturer";
    else if (c == 1)
        post = "docent";
    else if (c == 2)
        post = "academician";
    else if (c == 3)
        post = "professor";
    //cin >> a[i].post;
    cout << post << '\n';
    cout << "work:\n";
    for (int j = 0; j < 4; j++) {
        for (int h = 0; h < 5; h++) {
            //cout << j + 1 << ", " << h + 1 << ": ";
            //cin >> a[i].work[j][h];
            //work[j][h] = rand() % 2;
            //cout << work[j][h] << ' ';
        }
        cout << '\n';
    }
}

//functions

void print_tut(tutor a[]){
    cout << "table tutors:\n";
    for (int i = 0; i < 10; i++) {
        a[i].print();
    }
    cout << '\n';
}
void input_tut(tutor a[]) {
    srand(time(0));
    cout << "\nenter tutors:\n";
    for (int i = 0; i < 10; i++){
        a[i].input(i);
    }
    //return a;
}