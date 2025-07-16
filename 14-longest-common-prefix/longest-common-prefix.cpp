class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int end = -1;
        int n = strs.size();

        for(int i = 0; i< strs[0].size(); i++){
            if(strs[0][i] != strs[n-1][i]){
                if(i == 0) return "";
                end = i-1;
                break;

            }
        }

        if(end == -1) return strs[0];

        string ans = "";
        ans.append(strs[0], 0, end + 1);
        return ans;
    }
};