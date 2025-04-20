#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int ans : answers) {
            count[ans]++;
        }
        
        int total = 0;
        for (auto [k, v] : count) {
            // Group size is k+1
            int groupSize = k + 1;
            // Number of groups needed for v rabbits answering k
            int groups = (v + groupSize - 1) / groupSize; // ceiling of v / groupSize
            total += groups * groupSize;
        }
        
        return total;
    }
};
