class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);    
        vector<int> indegree(n, 0);       

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);  
                indegree[u]++;
            }
        }

        // Step 2: Kahn's algo - start from terminal nodes (indegree 0 in reversed graph)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
