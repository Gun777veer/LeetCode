#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minPrefix = 0, maxPrefix = 0, sum = 0;

        for (int d : differences) {
            sum += d;
            minPrefix = min(minPrefix, sum);
            maxPrefix = max(maxPrefix, sum);
        }

        long long minStart = lower - minPrefix;
        long long maxStart = upper - maxPrefix;

        return max(0LL, maxStart - minStart + 1);
    }
};
