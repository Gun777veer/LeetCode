#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Find the first positive number using binary search
        int left = 0, right = n - 1, firstPositive = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                firstPositive = mid;
                right = mid - 1;  // Search left for first occurrence
            } else {
                left = mid + 1;
            }
        }
        
        // Find the first zero or the end of negative numbers
        left = 0, right = n - 1;
        int firstNonNegative = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 0) {
                firstNonNegative = mid;
                right = mid - 1;  // Search left for first occurrence
            } else {
                left = mid + 1;
            }
        }
        
        int negCount = firstNonNegative;   // Count of negative numbers
        int posCount = n - firstPositive;  // Count of positive numbers
        
        return max(negCount, posCount);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {-2, -1, -1, 1, 2, 3};
    cout << sol.maximumCount(nums1) << endl;  // Output: 3

    vector<int> nums2 = {-3, -2, -1, 0, 0, 1, 2};
    cout << sol.maximumCount(nums2) << endl;  // Output: 3

    vector<int> nums3 = {5, 20, 66, 1314};
    cout << sol.maximumCount(nums3) << endl;  // Output: 4

    return 0;
}
