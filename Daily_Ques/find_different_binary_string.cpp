#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        int n = nums.size();
        std::string result = "";
        
        // Construct the string using diagonalization method
        for (int i = 0; i < n; ++i) {
            result += (nums[i][i] == '0') ? '1' : '0';  // Flip the diagonal bit
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> nums = {"111","011","001"};
    std::cout << "Different Binary String: " << sol.findDifferentBinaryString(nums) << std::endl;
    return 0;
}
