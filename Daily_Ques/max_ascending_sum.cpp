#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], currSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];  // Extend the ascending subarray
            } else {
                currSum = nums[i];  // Start a new subarray
            }
            maxSum = max(maxSum, currSum);  // Update the maximum sum
        }

        return maxSum;
    }
};

// Driver Code
#include <iostream>

int main() {
    Solution sol;
    
    vector<int> nums1 = {10, 20, 30, 5, 10, 50};
    cout << "Output: " << sol.maxAscendingSum(nums1) << endl;  // Expected: 65

    vector<int> nums2 = {10, 20, 30, 40, 50};
    cout << "Output: " << sol.maxAscendingSum(nums2) << endl;  // Expected: 150

    vector<int> nums3 = {12, 17, 15, 13, 10, 11, 12};
    cout << "Output: " << sol.maxAscendingSum(nums3) << endl;  // Expected: 33

    return 0;
}
