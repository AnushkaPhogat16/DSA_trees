class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<int> prev(n+1, 0);

        //tabulated lcs
        for(int i = 1; i <= n; i++){
            vector<int> curr(n+1, 0);
            for(int j = 1; j <= n; j++){
                if(s[i-1] == rev[j-1]){
                    if(j>0) curr[j] = 1+ prev[j-1];
                    else{
                        curr[j] = 1;
                    }

                }else{
                    if(j > 0) curr[j] = max(prev[j], curr[j-1]);
                    else{
                        curr[j] = prev[j];
                    }
                }
            }
            prev = curr;
        }   

        int lps = prev[n];
        return n - lps;  

    }
};