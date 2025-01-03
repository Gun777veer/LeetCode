#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0, prefixSum = 0;
        int validSplits = 0;
        
        // Compute the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        // Iterate through the array and check for valid splits
        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];  // Update prefix sum
            long long suffixSum = totalSum - prefixSum;  // Compute suffix sum
            if (prefixSum >= suffixSum) {
                validSplits++;
            }
        }
        
        return validSplits;
    }
};

int main() {
    vector<int> nums = {10, 4, -8, 7};
    Solution sol;
    cout << "Number of valid splits: " << sol.waysToSplitArray(nums) << endl;
    
    return 0;
}
