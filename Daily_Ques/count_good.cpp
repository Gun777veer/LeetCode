class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        long long res = 0;
        long long pairs = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            int val = nums[right];
            pairs += freq[val];  // adding current val makes freq[val] new pairs
            freq[val]++;

            // Shrink the window until the number of pairs drops below k
            while (pairs >= k) {
                res += n - right;  // all subarrays from [left, right] to [left, n-1] are good
                int removeVal = nums[left];
                freq[removeVal]--;
                pairs -= freq[removeVal];  // removing left, reduce pair count
                left++;
            }
        }

        return res;
    }
};
