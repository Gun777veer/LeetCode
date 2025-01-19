#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;  // No water can be trapped in less than a 3x3 grid

        // Min-heap to process the lowest height boundary first
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into the min-heap
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        // Directions for BFS (right, left, down, up)
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int waterTrapped = 0;
        int maxHeight = 0;

        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int h = cell[0], x = cell[1], y = cell[2];

            maxHeight = max(maxHeight, h);

            // Explore neighbors
            for (auto& d : directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (heightMap[nx][ny] < maxHeight) {
                        waterTrapped += maxHeight - heightMap[nx][ny];  // Water stored
                    }
                    pq.push({max(heightMap[nx][ny], maxHeight), nx, ny});
                }
            }
        }

        return waterTrapped;
    }
};
