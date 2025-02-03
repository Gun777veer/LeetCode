#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 1;  // A single element itself is a valid subarray.

    int incLen = 1, decLen = 1, maxLen = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            incLen++;
            decLen = 1;  // Reset decreasing sequence.
        } 
        else if (nums[i] < nums[i - 1]) {
            decLen++;
            incLen = 1;  // Reset increasing sequence.
        } 
        else {
            incLen = 1;
            decLen = 1;
        }

        maxLen = max(maxLen, max(incLen, decLen));
    }

    return maxLen;
}

// Driver code to test the function
int main() {
    vector<int> nums1 = {1, 4, 3, 3, 2};
    cout << "Output: " << longestSubarray(nums1) << endl;  // Expected: 2

    vector<int> nums2 = {3, 3, 3, 3};
    cout << "Output: " << longestSubarray(nums2) << endl;  // Expected: 1

    vector<int> nums3 = {3, 2, 1};
    cout << "Output: " << longestSubarray(nums3) << endl;  // Expected: 3

    return 0;
}
