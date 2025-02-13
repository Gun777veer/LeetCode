#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Min-heap to store the numbers in sorted order
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        // Keep processing until the smallest number in the heap is at least k
        while (minHeap.top() < k) {
            // Extract the two smallest elements
            int x = minHeap.top(); minHeap.pop();
            int y = minHeap.top(); minHeap.pop();

            // Compute the new value based on the given formula
            int new_value = x * 2 + y;

            // Insert the new value back into the heap
            minHeap.push(new_value);

            // Increment the operation count
            operations++;
        }

        return operations;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 11, 10, 1, 3};
    cout << sol.minOperations(nums1, 10) << endl;  // Output: 2

    vector<int> nums2 = {1, 1, 2, 4, 9};
    cout << sol.minOperations(nums2, 20) << endl;  // Output: 4

    return 0;
}
