#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

bool ISEXIST;

class ledger
{
public:
    char date[8];
    char name[30];
    char amt[20];
    bool isdebit;
};

int main() {

    char ch[40];
    ledger obj[1][40];
    int x = 0;
    fstream f;
    f.open("ledger.txt", ios::in | ios::out);

    while (f && x < 30) {
        f.getline(obj[0][x].date, 9, ',');
        cout << obj[0][x].date << "\n";
        f.getline(obj[0][x].name, 30, ',');
        cout << obj[0][x].name << "\n";
        f.getline(obj[0][x].amt, 20, ',');
        cout << obj[0][x].amt << "\n";
        f.getline(ch, 40, ',');
        if (ch == "debit") {
            obj[0][x].isdebit = true;
        }
        f.getline(ch, 40,'\n');
        //cout << obj[0][x].date << "  " << obj[0][x].name << "  " << obj[0][x].amt << "  " << obj[0][x].isdebit << "  " << x <<"\n";
        x++;
    }
}