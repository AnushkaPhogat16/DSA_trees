class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m, 0);

        for(int j = 0; j < m; j++){
            if(text1[0] == text2[j]) prev[j] = 1;
            else if(j > 0) prev[j] = prev[j-1];
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++){
                if(text1[i] == text2[j]){

                    if(j > 0)
                        curr[j] = 1 + prev[j-1];
                    else
                        curr[j] = 1;
                    
                    
                    
                } else {
                    if(j > 0)
                        curr[j] = max(prev[j], curr[j-1]);
                    else
                        curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m-1];
    }
};
