#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int whiteCount = 0, minWhite = n;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }

        minWhite = whiteCount; // Store the minimum encountered

        // Slide the window across the string
        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') whiteCount--; // Remove leftmost character
            if (blocks[i] == 'W') whiteCount++; // Add rightmost character
            minWhite = min(minWhite, whiteCount); // Update the minimum
        }

        return minWhite;
    }
};

// Example usage:
int main() {
    Solution sol;
    cout << sol.minimumRecolors("WBBWWBBWBW", 7) << endl; // Output: 3
    cout << sol.minimumRecolors("WBWBBBW", 2) << endl; // Output: 0
    return 0;
}
