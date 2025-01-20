#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> pos; // Maps value to its (row, col)
        
        // Store positions of numbers in mat
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCount(m, 0), colCount(n, 0); // Track painted rows & cols
        
        // Process arr and paint cells
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = pos[arr[i]];
            rowCount[r]++;
            colCount[c]++;
            
            // Check if any row or column is fully painted
            if (rowCount[r] == n || colCount[c] == m) {
                return i;
            }
        }
        
        return -1; // Should never reach here as a row/column will always be fully painted
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 3, 4, 2};
    vector<vector<int>> mat1 = {{1, 4}, {2, 3}};
    cout << "Output: " << sol.firstCompleteIndex(arr1, mat1) << endl; // Expected: 2

    vector<int> arr2 = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat2 = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    cout << "Output: " << sol.firstCompleteIndex(arr2, mat2) << endl; // Expected: 3
    
    return 0;
}
