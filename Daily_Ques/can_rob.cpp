class Solution {
public:
    bool canRob(vector<int>& nums, int k, int maxCapability) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= maxCapability) {
                count++;
                i++; // Skip next house since we can't rob adjacent houses
            }
            if (count >= k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canRob(nums, k, mid)) {
                result = mid;
                right = mid - 1; // Try to minimize max capability
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
