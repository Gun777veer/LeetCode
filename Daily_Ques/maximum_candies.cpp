#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid; // Number of children this pile can serve
        }
        return count >= k; // True if we can serve at least k children
    }

    int maximumCandies(vector<int>& candies, long long k) {
        if (k > accumulate(candies.begin(), candies.end(), 0LL)) return 0; // Not enough candies

        int left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(candies, k, mid)) {
                ans = mid; // Store the best answer
                left = mid + 1; // Try for larger candy distribution
            } else {
                right = mid - 1; // Reduce candy amount
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candies1 = {5,8,6};
    cout << sol.maximumCandies(candies1, 3) << endl; // Output: 5

    vector<int> candies2 = {2,5};
    cout << sol.maximumCandies(candies2, 11) << endl; // Output: 0

    return 0;
}
