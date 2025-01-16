#include <vector>

using namespace std;

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int xor1 = 0, xor2 = 0;

    // Compute XOR of all elements in nums1
    for (int num : nums1) {
        xor1 ^= num;
    }

    // Compute XOR of all elements in nums2
    for (int num : nums2) {
        xor2 ^= num;
    }

    // If any list has an even length, return 0
    if (nums1.size() % 2 == 0 || nums2.size() % 2 == 0) {
        return 0;
    }

    // Otherwise, return xor1 ^ xor2
    return xor1 ^ xor2;
}
