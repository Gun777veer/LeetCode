#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n + 1, -1);  // -1: unvisited, 0: color1, 1: color2
        int maxGroups = 1; // Tracks the maximum groups needed

        for (int i = 1; i <= n; i++) {
            if (color[i] != -1) continue; // Skip already visited nodes
            
            queue<int> q;
            q.push(i);
            color[i] = 0;
            int levelCount[2] = {0, 0}; // Count nodes in each bipartite level
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                levelCount[color[node]]++;

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node]; // Alternate the colors
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return -1;  // Conflict detected, graph is not bipartite
                    }
                }
            }
            
            // The longest path in this component is determined by max of two alternating levels
            maxGroups = max(maxGroups, levelCount[0] + levelCount[1]);
        }
        
        return maxGroups;
    }
};
