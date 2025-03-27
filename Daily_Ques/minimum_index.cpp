#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the dominant element
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int dominant = -1, dominantCount = 0;
        
        for (auto& [num, count] : freq) {
            if (count * 2 > n) {
                dominant = num;
                dominantCount = count;
                break;
            }
        }
        
        if (dominant == -1) {
            return -1;  // No dominant element found
        }
        
        // Step 2: Find the minimum valid split index
        int leftCount = 0;  // Count of dominant element in the left subarray
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == dominant) {
                leftCount++;
            }
            
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            
            int rightCount = dominantCount - leftCount;
            
            if (leftCount * 2 > leftSize && rightCount * 2 > rightSize) {
                return i;
            }
        }
        
        return -1;  // No valid split found
    }
};
