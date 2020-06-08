#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

class Table {
    int __size = -1;
public:
    std::vector<map<int, string>> line;
    Table() {
        line.resize(20);
    }
    void set_line(int i, int key, string value) {
        line[i][key] = value;
    }
    void print_line(int i) {
        map<int, string>::iterator it;
        for (it = line[i].begin(); it != line[i].end(); ++it) {
            cout << it->second << "  ";
        }
        cout << '\n';
    }
};

int main() {
    ifstream file("input.txt");
    string a;
    Table table;
    for (int i = 0; !file.eof(); ++i) {
        getline(file, a);
        table.set_line(i, 0, a);
        getline(file, a);
        table.set_line(i, 1, a);
        getline(file, a);
        table.set_line(i, 2, a);
        table.print_line(i);
        getline(file, a);
    }
    return 0;
}