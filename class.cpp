#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "class.h"

using std::cout, std::cin, std::endl, std::swap;

std::ifstream f;

//subject

void subject::print() {
    cout << name << ", " << num << " pair in week, " << stype << ", tutorID: " << tId;
}
void subject::input(int i){
    //cout << "\nsubject " << i + 1 << ":\nenter name: ";
    //cin >> name;
    f >> name; //read from file

    f >> num;
    //cout << "number pair in week: " << num;
    //cout << "\nsubject type (practic, lection): ";
    //cin >> stype;
    int c = rand() % 2;
    if (c == 0)
        stype = "lection";
    else if (c == 1)
        stype = "practic";
    tId = i;
    //cin >> tId;
    print();
}

//functions

void sort_sub(subject a[]){//сортировка предметов по убыванию часов
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10 - i - 1; j++)
            if (a[j].num < a[j+1].num)
                swap(a[j], a[j+1]);
        cout << '\n';
    }
}
void input_sub(subject a[]) {
    f.open("input-sub.txt");
    srand(time(0));
    cout << "input subjects:\n";
    for (int i = 0; i < 10; i++) {
        a[i].input(i);
        cout << endl;
    }
    f.close();
}
void print_sub(subject a[]) {
    cout << "\ntable subjects:\n";
    for (int i = 0; i < 10; i++) {
        a[i].print();
        cout << endl;
    }
}

//tutor

void tutor::print(){
    cout << "tutor " << name << ", " << post << ",\nwork: ";
    for (int j = 0; j < 4; j++) {
        for (int h = 0; h < 5; h++)
            cout << work[j][h] << ' ';
        cout << ' ';// '\n';
    }
}
void tutor::input(int i){
    //cout << "\ntutor " << i + 1 << ":\nenter name: ";
    //cin >> name;
    char tmp;
    tmp = f.get();
    name = tmp;

    //cout << "enter position: ";
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

    //cout << "work:\n";
    for (int j = 0; j < 4; j++) {
        for (int h = 0; h < 5; h++) {
            //cout << j + 1 << ", " << h + 1 << ": ";
            //cin >> a[i].work[j][h];
            if ((tmp = f.get()) != EOF)
                work[j][h] = tmp - '0';
        }
    }
    tmp = f.get();//get '\n'
    print();
    cout << endl;
    cout << "\n\n";
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
    f.open("input-tut.txt");
    cout << "\nenter tutors:\n";
    for (int i = 0; i < 10; i++){
        a[i].input(i);
    }
    f.close();
    //return a;
}