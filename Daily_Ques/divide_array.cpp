#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check if all counts are even
        for (auto& [key, count] : freq) {
            if (count % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};
