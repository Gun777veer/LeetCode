#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    void generateHappyStrings(int n, std::string curr, std::vector<std::string>& happyStrings) {
        if (curr.length() == n) {
            happyStrings.push_back(curr);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {  // Ensure consecutive chars are not the same
                generateHappyStrings(n, curr + ch, happyStrings);
            }
        }
    }

    std::string getHappyString(int n, int k) {
        std::vector<std::string> happyStrings;
        generateHappyStrings(n, "", happyStrings);

        if (k > happyStrings.size()) {
            return "";
        }
        return happyStrings[k - 1];  // k-th string (1-based index)
    }
};

int main() {
    Solution sol;
    int n = 3, k = 9;
    std::cout << "The " << k << "-th happy string of length " << n << " is: " << sol.getHappyString(n, k) << std::endl;
    return 0;
}
