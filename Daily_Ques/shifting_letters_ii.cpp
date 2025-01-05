#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0);  // Difference array to store shift increments

        // Step 1: Update the difference array based on shifts
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {  // Forward shift
                delta[start] += 1;
                delta[end + 1] -= 1;
            } else {  // Backward shift
                delta[start] -= 1;
                delta[end + 1] += 1;
            }
        }

        // Step 2: Compute cumulative sum to get the net shift at each index
        int shiftValue = 0;
        for (int i = 0; i < n; i++) {
            shiftValue += delta[i];  // Cumulative sum of delta
            int netShift = (shiftValue % 26 + 26) % 26;  // Normalize the shift to [0, 25]
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;   // Apply the net shift
        }

        return s;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    cout << "Result: " << sol.shiftingLetters(s, shifts) << endl;  // Output: "ace"

    s = "dztz";
    shifts = {{0, 0, 0}, {1, 1, 1}};
    cout << "Result: " << sol.shiftingLetters(s, shifts) << endl;  // Output: "catz"

    return 0;
}
