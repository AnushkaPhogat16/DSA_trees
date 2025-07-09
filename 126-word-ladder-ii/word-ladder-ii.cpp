class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        // 1) Early exit if endWord not in dict
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) 
            return {};

        // 2) BFS to build distance map and predecessor graph
        unordered_map<string,int> dist;               // word -> distance from beginWord
        unordered_map<string,vector<string>> preds;   // word -> list of words one-step before it
        queue<string> q;

        dist[beginWord] = 0;
        q.push(beginWord);

        int shortest = INT_MAX;

        while (!q.empty()) {
            string w = q.front(); q.pop();
            int d = dist[w] + 1;
            if (d > shortest) 
                break;  // we only care about layers up to the first time we see endWord

            string tmp = w;
            for (int i = 0; i < tmp.size(); ++i) {
                char orig = tmp[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    tmp[i] = c;
                    if (tmp == w) 
                        continue;

                    // If we found endWord, record predecessor & update shortest
                    if (tmp == endWord) {
                        preds[tmp].push_back(w);
                        shortest = d;
                    }
                    // If tmp is in dict and unseen, it's a new layer
                    else if (dict.count(tmp) && !dist.count(tmp)) {
                        dist[tmp] = d;
                        preds[tmp].push_back(w);
                        q.push(tmp);
                    }
                    // If tmp is seen at the same distance, add another predecessor
                    else if (dist.count(tmp) && dist[tmp] == d) {
                        preds[tmp].push_back(w);
                    }
                }
                tmp[i] = orig;
            }
        }

        // 3) If endWord was never reached, no ladders
        if (!preds.count(endWord))
            return {};

        // 4) Backtrack (DFS) from endWord to beginWord to build all paths
        vector<vector<string>> res;
        vector<string> path = { endWord };

        function<void(const string&)> dfs = [&](const string& word) {
            if (word == beginWord) {
                // we've built a path in reverse
                vector<string> rev = path;
                reverse(rev.begin(), rev.end());
                res.push_back(move(rev));
                return;
            }
            for (auto &prev : preds[word]) {
                path.push_back(prev);
                dfs(prev);
                path.pop_back();
            }
        };

        dfs(endWord);
        return res;
    }
};
