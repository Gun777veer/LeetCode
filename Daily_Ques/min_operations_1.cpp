#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        
        // Flatten the grid into a 1D array
        for (const auto& row : grid) {
            for (int val : row) {
                values.push_back(val);
            }
        }
        
        int n = values.size();
        
        // Check if all values have the same remainder when divided by x
        for (int i = 1; i < n; ++i) {
            if (values[i] % x != values[0] % x) {
                return -1;  // Impossible to make grid uni-value
            }
        }
        
        // Sort the values
        sort(values.begin(), values.end());
        
        // Find the median
        int median = values[n / 2];
        
        // Calculate the total operations needed
        int operations = 0;
        for (int val : values) {
            operations += abs(val - median) / x;
        }
        
        return operations;
    }
};
