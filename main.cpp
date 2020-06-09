#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

class Table {
    int __size = -1;
    vector<map<int, string>> line;
    map<string, string> audience;
public:
    Table() {
        line.resize(20);//5 days 4 lessons
    }
    void print(const auto &data, int i) {
        map<int, string>::iterator it;
        for (it = line[i].begin(); it != line[i].end(); ++it) {
            string a = it->second;
            int width = 24 - (a.size() - a.size() / 2);
            cout << setw(width) << left << '\t' << a;
        }
        cout << '\n';
    }
    void read_data() {     
        ifstream file("lessons.txt");
        string a;
        for (int i = 0; !file.eof(); ++i) {
            getline(file, a);
            line[i][0] = a;
            getline(file, a);
            line[i][1] = a;

            getline(file, a);
            line[i][2] = a;

            getline(file, a);
            line[i][3] = a;

            print(line, i);
            getline(file, a);//skip empty line
        }
        file.close();
        file.open("audience.txt");
        cout << "\naudience  | requirements\n";
        while(!file.eof()) {
            string i;
            getline(file, i);
            getline(file, a);
            audience[i] = a;
            cout << setw(12) << left << i << audience[i] << '\n';
        }
        file.close();
    }
};

int main() {
    Table table;
    table.read_data();
    return 0;
}