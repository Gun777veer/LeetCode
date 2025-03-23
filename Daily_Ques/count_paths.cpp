#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Build the graph using adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        // Step 2: Use Dijkstra's algorithm
        vector<long long> dist(n, LLONG_MAX);  // Store shortest distances
        vector<int> ways(n, 0);                // Store number of ways to reach each node in shortest time
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;

        // Initialize
        dist[0] = 0;
        ways[0] = 1;
        minHeap.push({0, 0});  // {distance, node}

        while (!minHeap.empty()) {
            auto [curTime, node] = minHeap.top();
            minHeap.pop();

            if (curTime > dist[node]) continue;

            for (auto& [neighbor, time] : graph[node]) {
                long long newTime = curTime + time;

                // Found a shorter path
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    ways[neighbor] = ways[node];
                    minHeap.push({newTime, neighbor});
                }
                // Found another way with the same shortest time
                else if (newTime == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];  // Number of ways to reach the destination
    }
};
