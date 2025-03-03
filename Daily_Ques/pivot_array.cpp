class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less_than, equal_to, greater_than;

        // Step 1: Distribute elements based on pivot
        for (int num : nums) {
            if (num < pivot) less_than.push_back(num);
            else if (num == pivot) equal_to.push_back(num);
            else greater_than.push_back(num);
        }

        // Step 2: Merge vectors in correct order
        vector<int> result;
        result.reserve(nums.size()); // Optimize memory allocation
        result.insert(result.end(), less_than.begin(), less_than.end());
        result.insert(result.end(), equal_to.begin(), equal_to.end());
        result.insert(result.end(), greater_than.begin(), greater_than.end());

        return result;
    }
};
