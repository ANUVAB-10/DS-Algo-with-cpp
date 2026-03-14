#include <bits/stdc++.h>
using namespace std;


// tc -> O(n*m); sc -> O(1);
void setMatrixZero(vector<vector<int>>& matrix) {
    int col0=1;

    // mark rows and cols 
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(matrix[i][j]==0) {
                // set rows vector to 0;
                matrix[i][0] = 0;
                 
                // set cols vector to 0
                if(j==0) {
                    col0=0;
                }
                else {
                    matrix[0][j] = 0;
                }
            }
        }
    }


    // now convert corresponding matrix element t0 zeroes acc to row and cols vector
    // start from last

    for(int i=1; i<matrix.size(); i++) {
        for(int j=1; j<matrix[0].size(); j++) {
            // check for row and cols
            if(matrix[i][j]!=0) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j]=0;
                }
            }
        }
    }


    // now convert the rows and cols vector starting with cols
    if(matrix[0][0]==0)
    for(int j=0; j<matrix[0].size(); j++) {
        matrix[0][j]=0;
    }
    

    // now the rows
    if(col0==0) {
        for(int i=0; i<matrix.size(); i++) {
            matrix[i][0]=0;
        }
    }


    // print them 
    cout << "Set matrix to 0 (Optimal): " << endl;
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        } cout << endl;
    }

}

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setMatrixZero(matrix);
}