#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0); // Initialize each node as its own parent
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    DSU dsu(n);

    // Step 1: Connect indices where swapping is allowed
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(nums[i] - nums[j]) <= limit) {
                dsu.unite(i, j);
            }
        }
    }

    // Step 2: Group elements by their connected components
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n; ++i) {
        groups[dsu.find(i)].push_back(nums[i]);
    }

    // Step 3: Sort each group to ensure the smallest lexicographical order
    for (auto& [key, group] : groups) {
        sort(group.begin(), group.end());
    }

    // Step 4: Reconstruct the answer array using sorted groups
    unordered_map<int, int> groupIndex;
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        int root = dsu.find(i);
        result[i] = groups[root][groupIndex[root]++];
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 5, 3, 9, 8};
    int limit1 = 2;
    vector<int> result1 = lexicographicallySmallestArray(nums1, limit1);
    
    for (int num : result1) cout << num << " ";
    cout << endl;

    vector<int> nums2 = {1, 7, 6, 18, 2, 1};
    int limit2 = 3;
    vector<int> result2 = lexicographicallySmallestArray(nums2, limit2);
    
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}
