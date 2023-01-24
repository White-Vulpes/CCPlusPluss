#include <iostream>
#include <fstream>

using namespace std;

class info{
  public:
    char date[9];
    char from[40];
    char to[40];
    char narr[100];
    char amt[30];
};

int main(){

    char ch[40];
    int count = 0;
    ofstream imp;
    imp.open("tally.xml",ios::out);
    ifstream data;
    data.open("book1.csv", ios::in);

    //gets the no. of lines in file
    while(data){
      data.getline(ch,40,'\n');
      count++;
    }
    data.clear();
    data.seekg(0);
    info obj[count-1];
    int x = 0;
    while(data && x < count){
        data.getline(obj[x].date, 9, ',');
        data.getline(obj[x].from, 40, ',');
        data.getline(obj[x].to, 40, ',');
        data.getline(obj[x].amt, 30, '\n');
        cout << obj[x].date << "   " << obj[x].from << "   " << obj[x].to << "   " << obj[x].amt << "\n";
    }

    //imp << "<ENVELOPE>\n<HEADER>\n<TALLYREQUEST> Import Data</TALLYREQUEST>\n</HEADER>\n<BODY>\n<IMPORTDATA>\n<REQUESTDESC>\n<REPORTNAME> All Masters</REPORTNAME>\n<STATICVARIABLES>\n<SVCURRENTCOMPANY> Mahaveer </SVCURRENTCOMPANY>\n</STATICVARIABLES>\n</REQUESTDESC>\n<REQUESTDATA> ";
}
