class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);        // Length of subset ending at i
        vector<int> parent(n, -1);   // For backtracking the subset

        int max_len = 0, max_index = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_index = i;
            }
        }

        // Reconstruct the result
        vector<int> result;
        for (int i = max_index; i != -1; i = parent[i]) {
            result.push_back(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
