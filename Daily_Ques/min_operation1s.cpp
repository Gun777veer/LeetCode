#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;

        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                // Flip the next 3 consecutive elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ops++;
            }
        }

        // Check if the entire array contains only 1s
        for (int num : nums) {
            if (num == 0) return -1;
        }

        return ops;
    }
};

int main() {
    vector<int> nums1 = {0, 1, 1, 1, 0, 0};
    vector<int> nums2 = {0, 1, 1, 1};

    Solution sol;
    cout << "Output 1: " << sol.minOperations(nums1) << endl;  // Output: 3
    cout << "Output 2: " << sol.minOperations(nums2) << endl;  // Output: -1

    return 0;
}
