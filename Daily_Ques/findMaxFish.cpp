class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return 0;
        
        int fish = grid[r][c];
        grid[r][c] = 0;  // Mark as visited
        
        // Explore all four directions
        int up = dfs(grid, r - 1, c);
        int down = dfs(grid, r + 1, c);
        int left = dfs(grid, r, c - 1);
        int right = dfs(grid, r, c + 1);
        
        return fish + up + down + left + right;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] > 0) {
                    maxFish = max(maxFish, dfs(grid, r, c));
                }
            }
        }
        return maxFish;
    }
};
