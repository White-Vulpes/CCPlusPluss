#include <iostream>

using namespace std;

void scrape(int x,int y,int data[9][9][9]){

    int avail[30] = {0};
    int ava = 0;
    for(int i = 0;i < 9;i++){
        if(data[x][0][i] != 0){
            avail[ava] = data[x][0][i];
            ava++;
        }
        if(data[i][0][y] != 0){
            avail[ava] = data[i][0][y];
            ava++;
        }
    }

    
   /* for (int j = 0; j < ava; j++) {
        cout << avail[j] << " ";
    }*/
}

int main() {

    int data[9][9][9] =  {{0, 0, 7, 8, 0, 3, 0, 0, 6},
                          {5, 0, 0, 9, 0, 0, 0, 3, 0},
                          {0, 1, 0, 0, 2, 0, 7, 0, 0},
                          {0, 0, 0, 0, 9, 0, 6, 0, 0},
                          {3, 0, 0, 4, 0, 7, 0, 0, 9},
                          {0, 0, 1, 0, 6, 0, 0, 0, 0},
                          {0, 0, 4, 0, 3, 0, 0, 7, 0},
                          {0, 3, 0, 0, 0, 6, 0, 0, 4},
                          {7, 0, 0, 2, 0, 4, 3, 0, 0}};

   /* for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << data[i][0][j] << "  ";
        }
        cout << "\n";
    }*/
    scrape(4, 4, data);
}