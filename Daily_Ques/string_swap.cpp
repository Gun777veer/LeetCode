#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // If the strings are already equal, no swap is needed.
        if (s1 == s2) return true;
        
        // Record indices where the characters differ.
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                diff.push_back(i);
        }
        
        // We need exactly 2 differences for one swap to potentially fix them.
        if (diff.size() != 2) return false;
        
        // Let the differing indices be i and j.
        int i = diff[0], j = diff[1];
        // Check if swapping s2[i] and s2[j] (or equivalently s1[i] and s1[j]) makes the strings equal.
        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};
