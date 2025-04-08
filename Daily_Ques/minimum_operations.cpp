class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        while (true) {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            // Check if there are any duplicates in the array
            for (int num : nums) {
                if (seen.count(num)) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(num);
            }

            // If no duplicates, we're done
            if (!hasDuplicate) break;

            // Remove the first 3 elements (or all if less than 3)
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            operations++;
        }

        return operations;
    }
};
