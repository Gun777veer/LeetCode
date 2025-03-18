#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        int mask = 0;  // To track the OR of current subarray
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Shrink the window while there's a bit collision
            while ((mask & nums[right]) != 0) {
                mask ^= nums[left];  // Remove the leftmost element
                ++left;
            }
            
            // Add current element to the mask
            mask |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << "Example 1 Output: " << solution.longestNiceSubarray(nums1) << endl;  // Output: 3

    // Example 2
    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << "Example 2 Output: " << solution.longestNiceSubarray(nums2) << endl;  // Output: 1

    return 0;
}
