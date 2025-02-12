#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxSum; // Stores max number for each digit sum
        int result = -1;

        for (int num : nums) {
            int digitSum = getDigitSum(num);

            // If a number with the same digit sum exists, update the result
            if (maxSum.count(digitSum)) {
                result = max(result, maxSum[digitSum] + num);
            }
            
            // Update the max number for this digit sum
            maxSum[digitSum] = max(maxSum[digitSum], num);
        }

        return result;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
