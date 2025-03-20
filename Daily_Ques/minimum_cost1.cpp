#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // Step 1: Build the graph using an adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // Step 2: BFS from each node to find the minimum AND cost to all other nodes
        vector<vector<int>> minCost(n, vector<int>(n, -1));

        for (int start = 0; start < n; ++start) {
            queue<pair<int, int>> q;
            q.push({start, INT_MAX});
            minCost[start][start] = INT_MAX;  // AND with self is max value

            while (!q.empty()) {
                auto [node, andCost] = q.front();
                q.pop();

                for (const auto& [neighbor, weight] : adj[node]) {
                    int newCost = andCost & weight;
                    
                    if (minCost[start][neighbor] == -1 || newCost > minCost[start][neighbor]) {
                        minCost[start][neighbor] = newCost;
                        q.push({neighbor, newCost});
                    }
                }
            }
        }

        // Step 3: Answering the queries
        vector<int> result;
        for (const auto& q : query) {
            int s = q[0], t = q[1];
            result.push_back(minCost[s][t]);
        }

        return result;
    }
};
