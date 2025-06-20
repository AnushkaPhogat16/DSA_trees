class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        
        helper(s, 0, 0, n, ans);
        // string each, no. of open, no. of closed, int n, vector ans

        return ans;
    }

    void helper(string s, int open, int closed, int n, vector<string>& ans){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            helper(s + '(' , open + 1, closed, n, ans);
        }

        if(closed < open){
            helper(s + ')', open, closed+1, n, ans);
        }
    }

};