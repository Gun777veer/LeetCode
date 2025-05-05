class Solution {
public:
    // MOD constant to be used for taking the remainder after division.
    static const int MOD = 1e9 + 7;

    int numTilings(int n) {
        // An array to hold the number of ways to tile for different subproblems.
        // f[0]: full cover, f[1]: top row is missing one, f[2]: bottom row is missing one, f[3]: both top and bottom are missing one (L-shape)
        long tilingWays[4] = {1, 0, 0, 0};

        // Iterate through all subproblem sizes from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Temporary array to compute the new number of tiling ways for the current subproblem.
            long newTilingWays[4] = {0, 0, 0, 0};

            // Full cover is obtained by adding one 2x2 tile or two 2x1 tiles to any of the four previous states.
            newTilingWays[0] = (tilingWays[0] + tilingWays[1] + tilingWays[2] + tilingWays[3]) % MOD;
            // Top row missing one can be obtained by adding a 2x1 tile to the previous state of bottom row missing one or both top and bottom missing one.
            newTilingWays[1] = (tilingWays[2] + tilingWays[3]) % MOD;
            // Bottom row missing one can be obtained by adding a 2x1 tile to the previous state of top row missing one or both top and bottom missing one.
            newTilingWays[2] = (tilingWays[1] + tilingWays[3]) % MOD;
            // Both top and bottom missing one can only be obtained by placing a 2x2 tile in the full cover state.
            newTilingWays[3] = tilingWays[0];

            // Update tilingWays array with the new computed values.
            memcpy(tilingWays, newTilingWays, sizeof(newTilingWays));
        }

        // Return the number of ways to fully cover a 2xN board.
        return tilingWays[0];
    }
};
Time
