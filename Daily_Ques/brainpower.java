class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] dp = new long[questions.length+1];
        for(int i = questions.length-1;i >= 0;i--){
            dp[i] = Math.max(questions[i][0]+dp[Math.min(i+questions[i][1]+1,n)], dp[i+1]);
        }
        return dp[0];
    }
}

// Solving Questions With Brainpower
