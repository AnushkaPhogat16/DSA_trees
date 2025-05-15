class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> op1;
        vector<string> op2;

        //start with 1
        // 1 0 1 0 1 0
        int prev = 0;
        for(int i = 0; i < groups.size(); i++){
            if(groups[i] != prev){
                op1.push_back(words[i]);
                prev = (prev == 0 ? 1 : 0);
            }else{
                continue;
            }
        }

        //start with 0
        // 0 1 0 1 0
        int prev2 = 1;
        for(int i = 0; i < groups.size(); i++){
            if(groups[i] != prev2){
                op2.push_back(words[i]);
                prev2 = (prev2 == 0 ? 1 : 0);
            }else{
                continue;
            }
        }

        return (op1.size() > op2.size() ? op1 : op2);
    }
};