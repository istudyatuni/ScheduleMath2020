#ifndef SUBJECT_H
#define SUBJECT_H
//#include <stdafx.h>
class subject {///класс предметов
public:
    std::string name;
    int num; // кол-во пар в неделю
    std::string stype; // тип предмета
    int tId; // id преподавателя
    subject(){};

    void print();
    void input(int i);
    friend void sort_sub(subject a[]);
    friend void calculate_shedule(subject&, tutor&, shedule&, audit&);
    int getnum(){
        return num;
    }
};

#endif // SUBJECT_H
