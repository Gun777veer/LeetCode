#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    
    vector<long long> top(n + 1, 0), bottom(n + 1, 0);

    // Compute prefix sums for the top and bottom rows
    for (int i = n - 1; i >= 0; --i) 
        top[i] = grid[0][i] + top[i + 1];

    for (int i = 0; i < n; ++i) 
        bottom[i + 1] = grid[1][i] + bottom[i];

    long long res = LLONG_MAX;

    // Try breaking at each column i
    for (int i = 0; i < n; ++i) {
        long long firstRobotLeaves = max(top[i + 1], bottom[i - 1]);
        res = min(res, firstRobotLeaves);
    }

    return (int)res;
}

int main() {
    vector<vector<int>> grid1 = {{2,5,4}, {1,5,1}};
    cout << gridGame(grid1) << endl; // Output: 4

    vector<vector<int>> grid2 = {{3,3,1}, {8,5,2}};
    cout << gridGame(grid2) << endl; // Output: 4

    vector<vector<int>> grid3 = {{1,3,1,15}, {1,3,3,1}};
    cout << gridGame(grid3) << endl; // Output: 7

    return 0;
}
