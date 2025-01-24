#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n, 0);
        
        // Reverse the graph: Store edges in the opposite direction
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u); // Reverse the edge
            }
        }
        
        queue<int> q;
        
        // Terminal nodes (nodes with no outgoing edges)
        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) { // Terminal node
                q.push(i);
            }
        }
        
        vector<bool> safe(n, false); // Track safe nodes
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true; // Mark node as safe
            
            for (int neighbor : reverseGraph[node]) {
                graph[neighbor].pop_back(); // Remove the edge
                if (graph[neighbor].empty()) { // If no outgoing edges left
                    q.push(neighbor);
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) result.push_back(i);
        }
        
        return result;
    }
};
