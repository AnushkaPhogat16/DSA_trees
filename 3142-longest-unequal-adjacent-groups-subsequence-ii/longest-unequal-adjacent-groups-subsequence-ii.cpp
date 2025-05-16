class Solution {
public:

    int hamming(const string &a, const string &b){
        int diff = 0;
        for(int k = 0; k < a.size(); k++){
            if(a[k] != b[k] && ++diff > 1){
                return diff;
            }
        }

        return diff;
    }


    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), prev(n, -1);

        //DP: try every pair (i < j)

        for(int j = 0; j < n; j++){
            for(int i = 0; i < j; i++){

                if(groups[i] != groups[j] && 
                words[i].size() == words[j].size() &&
                hamming(words[i], words[j]) == 1){
                    
                    if(dp[i] + 1 > dp[j]){
                        dp[j] = dp[i] + 1;
                        prev[j] = i;
                    }

                }
            }
        }

        // find best index where dp is maximum
        int bestLen = 0, bestEnd = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] > bestLen){
                bestLen = dp[i];
                bestEnd = i;
            }
        }

        //reconstruct the subsequence of words
        vector<string> answer;
        for(int curr = bestEnd; curr != -1; curr = prev[curr]){
            answer.push_back(words[curr]);
        }
        reverse(answer.begin(), answer.end());
        return answer;


    }
};