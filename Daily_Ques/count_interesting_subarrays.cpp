#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1; // base case: empty prefix
        long long result = 0;
        int count = 0;

        for (int num : nums) {
            if (num % modulo == k)
                count++;

            int curr = count % modulo;
            int target = (curr - k + modulo) % modulo;

            if (freq.count(target))
                result += freq[target];

            freq[curr]++;
        }

        return result;
    }
};
