// There is a grid with n rows and m columns. Some cells are colored black, and the rest of the cells are colored white.

// In one operation, you can select some black cell and do exactly one of the following:

// color all cells in its row black, or
// color all cells in its column black.
// You are given two integers r and c. Find the minimum number of operations required to make the cell in row r and column c black, or determine that it is impossible.

// Input
// The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains four integers n, m, r, and c (1≤n,m≤50; 1≤r≤n; 1≤c≤m) — the number of rows and the number of columns in the grid, and the row and column of the cell you need to turn black, respectively.

// Then n lines follow, each containing m characters. Each of these characters is either 'B' or 'W' — a black and a white cell, respectively.

// Output
// For each test case, if it is impossible to make the cell in row r and column c black, output −1.

// Otherwise, output a single integer — the minimum number of operations required to make the cell in row r and column c black.

#include <iostream>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    char mat[50][50];
    for(int i=0; i<cases; i++){
        int l,m,a,b;
        cin>>l>>m>>a>>b;
        bool ban=0;
        for(int i=0; i<l; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
                if(mat[i][j] == 'B'){
                    ban=1;
                }
            }
        }
        if(!ban){
            cout<<-1<<endl;
        }
        else{
            a--;
            b--;
            if(mat[a][b] == 'B'){
                cout<<0<<endl;
            }
            else{
                bool in=0;
                for(int i=0; i<l; i++){
                    if(mat[i][b] == 'B'){
                        in=1;
                    }
                }
                for(int i=0; i<m; i++){
                    if(mat[a][i] == 'B'){
                        in=1;
                    }
                }
                if(in){
                    cout<<1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
            }

        }
    }
}




