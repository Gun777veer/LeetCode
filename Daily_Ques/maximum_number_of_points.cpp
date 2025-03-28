#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();

        vector<int> answer(k, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Directions for moving in 4 directions: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Store queries with their original index to sort them later
        vector<pair<int, int>> indexed_queries;
        for (int i = 0; i < k; ++i) {
            indexed_queries.emplace_back(queries[i], i);
        }
        
        // Sort queries by value
        sort(indexed_queries.begin(), indexed_queries.end());

        // Min-heap to prioritize lower cell values
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        visited[0][0] = true;
        
        int points = 0;  
        int current_query_index = 0;

        while (current_query_index < k) {
            int current_query = indexed_queries[current_query_index].first;
            int original_index = indexed_queries[current_query_index].second;

            // Expand BFS region while cell values are smaller than current query
            while (!pq.empty() && pq.top().first < current_query) {
                auto [val, pos] = pq.top();
                int row = pos.first, col = pos.second;
                pq.pop();

                points++;

                // Explore all 4 directions
                for (auto& dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        pq.push({grid[newRow][newCol], {newRow, newCol}});
                    }
                }
            }

            answer[original_index] = points;
            current_query_index++;
        }

        return answer;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries1 = {5, 6, 2};
    
    vector<int> result1 = sol.maxPoints(grid1, queries1);
    cout << "Output 1: ";
    for (int res : result1) {
        cout << res << " ";
    }
    cout << endl;

    vector<vector<int>> grid2 = {{5, 2, 1}, {1, 1, 2}};
    vector<int> queries2 = {3};

    vector<int> result2 = sol.maxPoints(grid2, queries2);
    cout << "Output 2: ";
    for (int res : result2) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
