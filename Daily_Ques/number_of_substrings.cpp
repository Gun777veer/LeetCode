class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0, result = 0;
        vector<int> count(3, 0); // Count occurrences of 'a', 'b', and 'c'
        
        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++; // Increase count for current character
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) { // All 'a', 'b', 'c' are present
                result += (n - right); // All substrings ending at `right` are valid
                count[s[left] - 'a']--; // Shrink window from the left
                left++;
            }
        }
        
        return result;
    }
};
