#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;    // Adjacency list
        unordered_map<string, int> inDegree;            // Track missing ingredients

        // Initialize in-degree for all recipes
        for (int i = 0; i < recipes.size(); ++i) {
            inDegree[recipes[i]] = ingredients[i].size();
            
            // Create graph: ingredients -> recipe
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        // Add all supplies to the queue
        queue<string> q;
        unordered_set<string> available(supplies.begin(), supplies.end());
        
        for (const string& s : supplies) {
            q.push(s);
        }

        vector<string> result;

        // BFS to process recipes
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            // If the current item is a recipe, add it to the result
            if (inDegree.find(item) != inDegree.end()) {
                result.push_back(item);
            }

            // Traverse dependencies
            for (const string& next : graph[item]) {
                --inDegree[next];

                // If all ingredients are available, add the recipe to the queue
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return result;
    }
};
