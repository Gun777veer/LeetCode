#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string result = "1";
        
        for (int i = 2; i <= n; ++i) {
            std::string next = "";
            int count = 1;
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == result[j - 1]) {
                    ++count;
                } else {
                    next += std::to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            // Add the last group
            next += std::to_string(count) + result.back();
            result = next;
        }

        return result;
    }
};
