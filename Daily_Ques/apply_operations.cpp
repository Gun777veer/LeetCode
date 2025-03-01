#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Apply the given operation
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move all zeros to the end using two-pointer approach
        int insertPos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[insertPos]);
                insertPos++;
            }
        }

        return nums;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1, 1, 0};
    vector<int> result1 = sol.applyOperations(nums1);
    for (int num : result1) cout << num << " ";
    cout << endl;

    vector<int> nums2 = {0, 1};
    vector<int> result2 = sol.applyOperations(nums2);
    for (int num : result2) cout << num << " ";
  
