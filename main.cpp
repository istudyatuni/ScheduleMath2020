#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

class Table {
    vector<map<int, string>> m_line;
    //0 - title, 1 - type, 2 - name, 3 - requirements, 4 - freedom location
    map<string, string> audience;
    string count_suitable_audience(int i) {
        map<string, string>::iterator it = audience.begin();
        int a = 0;
        for (;it != audience.end(); it++) {
            if (it->second == m_line[i][3]) {
                a++;
            }
        }
        string s = to_string(a);
        return s;
    }
    void freedom_location() {
        for (int i = 1; i < m_line.size(); i++) {
            m_line[i][4] = count_suitable_audience(i);
        }
    }
    void read_data() {     
        ifstream file("input/lessons.txt");
        string a;
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
        while(!file.eof()) {
            string i;
            getline(file, i);
            getline(file, a);
            audience[i] = a;
        }
        file.close();
    }
    void print_line(int i) {
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
            cout.fill(' ');
            j++;
        }
        cout << '\n';
    }
public:
    Table() {
        m_line.resize(20);//5 days 4 lessons
        m_line[0][0] = "Название";
        m_line[0][1] = "Тип";
        m_line[0][2] = "Имя преподавателя";
        m_line[0][3] = "\tДоп требования";
        m_line[0][4] = "Свобода расположения";
        read_data();
        freedom_location();
        print();
    }
    void print() {
        for (int i = 0; i < m_line.size(); i++) {
            print_line(i);
        }
        cout << "\naudience  | requirements\n";
        map<string, string>::iterator it = audience.begin();
        for (;it != audience.end(); it++) {
            cout << setw(12) << left;
            cout << it->first << it->second << '\n';
        }
    }
};

int main() {
    Table table;
    return 0;
}