#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> last(26, 0);

        // Step 1: Record the last occurrence of each character
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }

        // Step 2: Create partitions
        vector<int> result;
        int start = 0, end = 0;

        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i] - 'a']);
            
            if (i == end) {  // End of a partition
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
