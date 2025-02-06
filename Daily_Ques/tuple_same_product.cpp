#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        // Map product -> count of pairs with that product.
        unordered_map<int, int> productCount;
        
        // Consider all unordered pairs (i, j) with i < j.
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }
        
        int result = 0;
        // For each product, if there are count pairs, add count*(count-1)*4 to the result.
        for (auto& p : productCount) {
            int count = p.second;
            if (count > 1) {
                result += count * (count - 1) * 4;
            }
        }
        
        return result;
    }
};
