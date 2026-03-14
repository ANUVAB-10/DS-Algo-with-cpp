#include<bits/stdc++.h>
using namespace std;

void spiralPrint(vector<vector<int>>&matrix) {
    int top=0;
    int bottom=matrix.size()-1;
    int left=0;
    int right=matrix[0].size()-1;

    while(top<=bottom && left <= right) {
        // right print
        for(int i=left; i<=right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        // bottom print
        for(int i=top; i<=bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        // left print
        for(int i=right; i>=left; i--) {
            cout << matrix[bottom][i] << " ";
        }
        bottom--;

        // up print
        for(int i=bottom; i>=top; i--) {
            cout << matrix[i][left] << " ";
        }
        left++;
    }

}

int main() {
    vector<vector<int>> matrix = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };

    spiralPrint(matrix);
}