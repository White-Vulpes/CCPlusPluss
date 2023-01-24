#include <iostream>

using namespace std;

int add(int i) {
    if (i == 10) {
        return 0;
    }
    if (i != 0) {
        cout << i-- << " **** ";
        add(i);
        cout << i << " ```` ";
    }
}
int main() {
    int i = 0;
    cout << "Enter Number : ";
    cin >> i;
    add(i);
    // cout << "\n Answer is : " << add(i);
}