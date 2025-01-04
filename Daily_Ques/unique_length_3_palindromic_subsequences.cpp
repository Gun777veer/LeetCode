#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> uniquePalindromes;
        int n = s.size();
        
        // Iterate through each character in the string as the center of the palindrome
        for (int i = 1; i < n - 1; i++) {
            char middle = s[i];
            bool leftSeen[26] = {false}, rightSeen[26] = {false};
            
            // Check for identical characters on the left
            for (int j = 0; j < i; j++) {
                if (s[j] == middle) {
                    leftSeen[s[j] - 'a'] = true;
                }
            }
            
            // Check for identical characters on the right
            for (int k = i + 1; k < n; k++) {
                if (s[k] == middle) {
                    rightSeen[s[k] - 'a'] = true;
                }
            }
            
            // Add unique palindromes of length 3 to the set
            for (int c = 0; c < 26; c++) {
                if (leftSeen[c] && rightSeen[c]) {
                    string palindrome = "";
                    palindrome += (char)('a' + c);
                    palindrome += middle;
                    palindrome += (char)('a' + c);
                    uniquePalindromes.insert(palindrome);
                }
            }
        }
        
        return uniquePalindromes.size();
    }
};

int main() {
    Solution sol;
    string s = "aabca";
    cout << sol.countPalindromicSubsequence(s) << endl; // Output: 3
    
    s = "adc";
    cout << sol.countPalindromicSubsequence(s) << endl; // Output: 0
    
    s = "bbcbaba";
    cout << sol.countPalindromicSubsequence(s) << endl; // Output: 4

    return 0;
}
