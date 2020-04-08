#include <cstring>
using namespace std;

class shedule;
class audit;
class tutor;
class subject {///класс предметов
public:
    string name;
    int num; // кол-во пар в неделю
    string stype; // тип предмета
    int tId; // id преподавателя
    subject(){};
    void print() {
        cout << "\n* * " << name << ":\n";
        cout << num << " pair in week\n";
        cout << stype << endl;
        cout << "tutor ID: " << tId << "\n";
    }
    void input(int i){
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
    friend void sort_sub(subject a[]);
    friend void calculate_shedule(subject&, tutor&, shedule&, audit&);
    int getnum(){
        return num;
    }
};
class tutor {///преподаватели
public:
    int work[4][5];
    string name;
    string post; //должность (степени) - senior lecturer
                //docent, academician, professor
    tutor(){};
    //нужен метод записи в массив из массива-параметра
    //void write_work ()
    void input_work () {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << i << '.' << j << ": ";
                cin >> work[i][j];
            }
        }
    }
    void print(){
        cout << "tutor " << name << ", " << post;
        cout << "\nwork:\n";
        for (int j = 0; j < 4; j++) {
            for (int h = 0; h < 5; h++)
                cout << work[j][h] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    void input(int i){
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
};
class audit {//аудитории
    int aId;
    int num; // номер аудитории
    int vol; // объем аудитории
    int type; // тип аудитории компьютерная - 1, обычная - 0
public:
    audit(){};
};
class shedule {//само расписание
public:
    string name;//предмет
    string tut;
    int aud;
    friend void calculate_shedule(subject&, tutor&, shedule&, audit&);
    shedule(){};
};