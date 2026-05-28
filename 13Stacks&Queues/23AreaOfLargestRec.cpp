#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st; // storing indices
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (st.empty() ||
            heights[i] > heights[st.top()]) { // eqaulity check remains
            st.push(i);
        } else {
            // current element is smaller
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int top =
                    heights[st.top()]; // take the top elm and cal area
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxArea = max(maxArea, (top * (nse - pse - 1)));
            }
            st.push(i);
        }
    }

    // for remaining elements
    while (!st.empty()) {
        int top = heights[st.top()];
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        int nse = heights.size();
        maxArea = max(maxArea, (top * (nse - pse - 1)));
    }

    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1') heights[j] += 1;
            else heights[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}


int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << "Area of largest rectangle: " << maximalRectangle(matrix) << endl;
}