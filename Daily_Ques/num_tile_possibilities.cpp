#include <vector>
#include <string>

class Solution {
public:
    void backtrack(std::vector<int>& freq, int& count) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // Use this letter
                count++;
                freq[i]--;

                // Recurse to form more sequences
                backtrack(freq, count);

                // Backtrack (restore frequency)
                freq[i]++;
            }
        }
    }

    int numTilePossibilities(std::string tiles) {
        std::vector<int> freq(26, 0);
        
        // Count frequency of each letter in the input string
        for (char c : tiles) {
            freq[c - 'A']++;
        }
        
        int count = 0;
        backtrack(freq, count);
        
        return count;
    }
};
