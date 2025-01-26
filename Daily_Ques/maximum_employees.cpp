#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0), longestPath(n, 1);
        vector<vector<int>> adj(n);
        
        // Build graph and compute in-degrees
        for (int i = 0; i < n; ++i) {
            adj[favorite[i]].push_back(i);
            indegree[i]++;
        }
        
        // Step 1: Find longest path for nodes leading to a 2-cycle
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            longestPath[v] = max(longestPath[v], longestPath[u] + 1);
            if (--indegree[v] == 0) q.push(v);
        }

        // Step 2: Process cycles
        int maxCycleSize = 0, sumTwoCycles = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && indegree[i] > 0) {
                int cycleSize = 0, u = i;
                
                while (!visited[u]) {
                    visited[u] = true;
                    u = favorite[u];
                    cycleSize++;
                }

                if (cycleSize == 2) { // Handle 2-cycle separately
                    sumTwoCycles += longestPath[i] + longestPath[favorite[i]];
                } else {
                    maxCycleSize = max(maxCycleSize, cycleSize);
                }
            }
        }

        return max(maxCycleSize, sumTwoCycles);
    }
};
