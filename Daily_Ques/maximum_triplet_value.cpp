#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        // Prefix max (stores the largest nums[i] before index j)
        vector<long long> prefix_max(n);
        prefix_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], (long long)nums[i]);
        }

        // Suffix max (stores the largest nums[k] after index j)
        vector<long long> suffix_max(n);
        suffix_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], (long long)nums[i]);
        }

        // Calculate maximum triplet value
        long long max_value = 0;
        for (int j = 1; j < n - 1; j++) {
            long long i_max = prefix_max[j - 1];  // Best nums[i] before j
            long long k_max = suffix_max[j + 1];  // Best nums[k] after j
            max_value = max(max_value, (i_max - nums[j]) * k_max);
        }

        return max_value;
    }
};

// Test cases
int main() {
    Solution sol;

    vector<int> nums1 = {12, 6, 1, 2, 7};
    cout << sol.maximumTripletValue(nums1) << endl;  // Output: 77

    vector<int> nums2 = {1, 10, 3, 4, 19};
    cout << sol.maximumTripletValue(nums2) << endl;  // Output: 133

    vector<int> nums3 = {1, 2, 3};
    cout << sol.maximumTripletValue(nums3) << endl;  // Output: 0

    vector<int> nums4 = {5, 8, 3, 10, 7};
    cout << sol.maximumTripletValue(nums4) << endl;  // Output: 70

    return 0;
}
