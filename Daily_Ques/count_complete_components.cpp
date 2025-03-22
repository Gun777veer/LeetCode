#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Step 2: Track visited nodes
        vector<bool> visited(n, false);
        int completeCount = 0;

        // Step 3: Traverse all components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_set<int> component;
                int edgeCount = 0;

                // Perform DFS to traverse the connected component
                dfs(i, graph, visited, component, edgeCount);

                int numVertices = component.size();
                int requiredEdges = (numVertices * (numVertices - 1)) / 2;

                // Since DFS counts each edge twice, divide edgeCount by 2
                if (edgeCount / 2 == requiredEdges) {
                    ++completeCount;
                }
            }
        }

        return completeCount;
    }

private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, unordered_set<int>& component, int& edgeCount) {
        visited[node] = true;
        component.insert(node);

        for (int neighbor : graph[node]) {
            ++edgeCount;  // Count each edge
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, component, edgeCount);
            }
        }
    }
};
