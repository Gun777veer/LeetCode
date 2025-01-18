#include <vector>
#include <deque>
#include <limits>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Direction mappings for 1 → right, 2 → left, 3 → down, 4 → up
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Cost matrix initialized to a large value
        vector<vector<int>> cost(m, vector<int>(n, numeric_limits<int>::max()));

        deque<pair<int, int>> dq; // Deque for 0-1 BFS
        
        // Start from (0,0) with cost 0
        cost[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            // Try moving in all 4 directions
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost[x][y] + (grid[x][y] != i + 1); // Cost is 0 if following the given direction
                    
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;

                        if (grid[x][y] == i + 1) {
                            dq.push_front({nx, ny});  // Prioritize zero-cost moves
                        } else {
                            dq.push_back({nx, ny});   // Process higher-cost moves later
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
