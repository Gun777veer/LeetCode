#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        
        // Step 1: Compute LCS using DP
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Construct SCS from LCS
        int i = m, j = n;
        string scs = "";
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs += str1[i - 1];
                i--; j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                scs += str1[i - 1];
                i--;
            } else {
                scs += str2[j - 1];
                j--;
            }
        }
        
        // Append remaining characters from str1
        while (i > 0) {
            scs += str1[i - 1];
            i--;
        }
        
        // Append remaining characters from str2
        while (j > 0) {
            scs += str2[j - 1];
            j--;
        }

        // Reverse to get the correct order
        reverse(scs.begin(), scs.end());
        
        return scs;
    }
};

int main() {
    Solution sol;
    cout << sol.shortestCommonSupersequence("abac", "cab") << endl;  // Output: "cabac"
    cout << sol.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa") << endl;  // Output: "aaaaaaaa"
    return 0;
}
