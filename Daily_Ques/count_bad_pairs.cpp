#include <unordered_map>
#include <vector>

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        std::unordered_map<int, long long> freq;
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            if (freq.find(diff) != freq.end()) {
                goodPairs += freq[diff];  // Add all previously seen indices with the same diff
            }
            freq[diff]++;
        }
        
        return totalPairs - goodPairs;
    }
};
