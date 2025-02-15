#include <iostream>
#include <string>

class Solution {
public:
    bool isValidPartition(std::string s, int target, int start = 0, int sum = 0) {
        if (start == s.size()) return sum == target;
        
        int num = 0;
        for (int i = start; i < s.size(); ++i) {
            num = num * 10 + (s[i] - '0');
            if (isValidPartition(s, target, i + 1, sum + num)) return true;
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (isValidPartition(std::to_string(square), i)) {
                result += square;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int n = 37;
    std::cout << "Punishment Number of " << n << " is: " << sol.punishmentNumber(n) << std::endl;
    return 0;
}
