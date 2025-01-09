#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int n = pref.size();
        
        for (const string& word : words) {
            if (word.size() >= n && word.substr(0, n) == pref) {
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<string> words1 = {"pay", "attention", "practice", "attend"};
    string pref1 = "at";
    cout << "Output: " << solution.prefixCount(words1, pref1) << endl; // Expected output: 2
    
    // Test case 2
    vector<string> words2 = {"leetcode", "win", "loops", "success"};
    string pref2 = "code";
    cout << "Output: " << solution.prefixCount(words2, pref2) << endl; // Expected output: 0
    
    return 0;
}
