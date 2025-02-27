#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index; // Store the index of each element
        unordered_map<int, int> dp;    // DP table to store Fibonacci-like sequences
        int maxLen = 0;

        // Populate the index map
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Iterate over all pairs (arr[i], arr[j])
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int x = arr[j] - arr[i]; // Expected previous element
                if (x < arr[i] && index.find(x) != index.end()) {
                    int k = index[x]; // Find the index of x
                    int key = k * n + i; // Unique key for DP table
                    dp[i * n + j] = dp.count(key) ? dp[key] + 1 : 3;
                    maxLen = max(maxLen, dp[i * n + j]);
                }
            }
        }

        return maxLen;
    }
};
