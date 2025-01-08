#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        
        // Check all pairs (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        
        // Check if str1 is both prefix and suffix of str2
        if (len1 > len2) return false;  // str1 cannot be a prefix/suffix if it's longer than str2
        
        return (str2.substr(0, len1) == str1 && str2.substr(len2 - len1, len1) == str1);
    }
};

int main() {
    Solution sol;
    vector<string> words1 = {"a", "aba", "ababa", "aa"};
    cout << sol.countPrefixSuffixPairs(words1) << endl;  // Output: 4
    
    vector<string> words2 = {"pa", "papa", "ma", "mama"};
    cout << sol.countPrefixSuffixPairs(words2) << endl;  // Output: 2
    
    vector<string> words3 = {"abab", "ab"};
    cout << sol.countPrefixSuffixPairs(words3) << endl;  // Output: 0
    
    return 0;
}
