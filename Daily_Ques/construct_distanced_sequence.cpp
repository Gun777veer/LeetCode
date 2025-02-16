#include <iostream>
#include <vector>

class Solution {
public:
    bool backtrack(std::vector<int>& result, std::vector<bool>& used, int n, int index) {
        if (index == result.size()) return true; // Successfully filled the sequence

        // If the current index is already occupied, move forward
        if (result[index] != 0) return backtrack(result, used, n, index + 1);

        // Try placing numbers from n down to 1
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue; // Skip if already placed
            
            if (num == 1) { // Place 1 at the current position
                result[index] = 1;
                used[1] = true;
                if (backtrack(result, used, n, index + 1)) return true;
                used[1] = false;
                result[index] = 0;
            } else { // Place num at index and index + num
                int nextIndex = index + num;
                if (nextIndex < result.size() && result[nextIndex] == 0) {
                    result[index] = result[nextIndex] = num;
                    used[num] = true;
                    if (backtrack(result, used, n, index + 1)) return true;
                    used[num] = false;
                    result[index] = result[nextIndex] = 0; // Undo move
                }
            }
        }
        return false;
    }

    std::vector<int> constructDistancedSequence(int n) {
        std::vector<int> result(2 * n - 1, 0); // Sequence of size 2n - 1
        std::vector<bool> used(n + 1, false); // Track used numbers
        backtrack(result, used, n, 0);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 5;
    std::vector<int> result = sol.constructDistancedSequence(n);
    
    std::cout << "Lexicographically largest sequence for n=" << n << ":\n";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
