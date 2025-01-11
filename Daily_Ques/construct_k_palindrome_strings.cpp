#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canConstruct(string s, int k) {
    // If k is greater than the length of s, return false
    if (k > s.length()) return false;
    
    // Count frequency of each character
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    
    // Count the number of characters with odd frequencies
    int oddCount = 0;
    for (auto& entry : charCount) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }
    
    // Check if the number of odd characters is less than or equal to k
    return oddCount <= k;
}

int main() {
    // Test cases
    string s1 = "annabelle";
    int k1 = 2;
    cout << (canConstruct(s1, k1) ? "true" : "false") << endl;  // Output: true

    string s2 = "leetcode";
    int k2 = 3;
    cout << (canConstruct(s2, k2) ? "true" : "false") << endl;  // Output: false

    string s3 = "true";
    int k3 = 4;
    cout << (canConstruct(s3, k3) ? "true" : "false") << endl;  // Output: true

    return 0;
}
