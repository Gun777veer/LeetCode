class Solution {
public:
    vector<int> directions = {0, 1, 0, -1, 0}; // For moving in 4 directions

    int dfs(vector<vector<int>>& grid, int i, int j, int islandId, unordered_map<int, int>& islandSizes) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) 
            return 0;
        
        grid[i][j] = islandId; // Mark the cell with the island ID
        int size = 1;

        for (int d = 0; d < 4; d++) { // Move in 4 directions
            size += dfs(grid, i + directions[d], j + directions[d + 1], islandId, islandSizes);
        }
        
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> islandSizes; // Map to store island ID -> size
        int islandId = 2; // Unique ID for islands (starting from 2)
        int maxIsland = 0;

        // Step 1: Identify all islands and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSizes[islandId] = dfs(grid, i, j, islandId, islandSizes);
                    maxIsland = max(maxIsland, islandSizes[islandId]);
                    islandId++;
                }
            }
        }

        // Step 2: Try flipping a zero and calculate the new island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    for (int d = 0; d < 4; d++) { // Check adjacent cells
                        int ni = i + directions[d], nj = j + directions[d + 1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] > 1) {
                            neighbors.insert(grid[ni][nj]);
                        }
                    }
                    int newSize = 1; // Include the new flipped cell
                    for (int id : neighbors) {
                        newSize += islandSizes[id]; // Add sizes of neighboring islands
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
