#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1)); // Initialize with -1 (unvisited land cells)
    queue<pair<int, int>> q;
    
    // Directions for moving in 4 possible directions
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Add all water cells (height = 0) to the queue
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isWater[i][j] == 1) {
                height[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    // BFS to assign heights
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && height[nr][nc] == -1) {
                height[nr][nc] = height[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    return height;
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Driver code
int main() {
    vector<vector<int>> isWater = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    vector<vector<int>> result = highestPeak(isWater);
    
    printMatrix(result);
    return 0;
}
