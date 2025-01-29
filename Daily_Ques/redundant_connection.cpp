#include <vector>
using namespace std;

// Union-Find (Disjoint Set Union) class
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by rank
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

private:
    vector<int> parent;
    vector<int> rank;
};

vector<int> findRedundantEdge(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind uf(n + 1);  // We use 1-based indexing
    
    vector<int> result;
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        
        if (uf.find(u) == uf.find(v)) {
            // If they are in the same set, this edge forms a cycle
            result = edge;  // We update the result to the latest edge causing a cycle
        } else {
            uf.unionSets(u, v);  // Otherwise, union the two sets
        }
    }
    
    return result;  // Return the last edge that forms a cycle
}
