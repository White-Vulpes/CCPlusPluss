#include <iostream>

using namespace std;

int sudoku[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

int rough[9][9][9] = {0};

void solver(){
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            if(sudoku[i][j] == 0){
                for(int k = 0;k < 9;k++){
                    if(sudoku[i][k] != 0){
                        if (rough[i][j][sudoku[i][k] - 1] == 0){
                            rough[i][j][sudoku[i][k] - 1] = 1;
                        }
                    }
                    if(sudoku[k][j] != 0){
                        if (rough[i][j][sudoku[k][j] - 1] == 0){
                            rough[i][j][sudoku[k][j] - 1] = 1;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    solver();
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            cout << "[" << i << "," << j << "] : "; 
            for(int k = 0;k < 9;k++){
               if(rough[i][j][k] == 0){
                   cout << k + 1 << ",";
               }
            }
            cout <<"\n";
        }
    }
    return 0;
}