class Solution {
public:
    int n;

    void dfs(unordered_map<int, vector<int>>& adj, int u ,vector<bool>& visited){
        visited[u] = true;

        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {        

        n = isConnected.size();
        vector<bool> vis(n, false);
        int count = 0;

        // make graph
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, i, vis);
                count++;
            }
        }

        return count;   
    }
};