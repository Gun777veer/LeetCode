class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] dp = new long[n + 1]; // DP array to store max points from each index

        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Solve the current question
            long solve = questions[i][0] + dp[Math.min(i + questions[i][1] + 1, n)];
            
            // Option 2: Skip the current question
            long skip = dp[i + 1];

            // Store the maximum of both choices
            dp[i] = Math.max(solve, skip);
        }
        
        return dp[0]; // Maximum points starting from index 0
    }
}
