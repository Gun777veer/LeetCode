#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& nums) {
    int count = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n])  // Check for decreasing pair
            count++;
        if (count > 1)  // More than one drop means not rotated sorted
            return false;
    }
    return true;
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    vector<int> nums3 = {1, 2, 3};

    cout << check(nums1) << endl;  // Output: true
    cout << check(nums2) << endl;  // Output: false
    cout << check(nums3) << endl;  // Output: true

    return 0;
}
