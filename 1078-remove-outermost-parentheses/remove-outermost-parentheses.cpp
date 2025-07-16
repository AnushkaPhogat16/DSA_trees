class Solution {
public:
    string removeOuterParentheses(string s) {
        // find start nd end index of every primitive
        // remove 1st nd last bracket
        // add it to string

        vector<pair<int, int>> startEndInd;
        stack<int> st;

        int start = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                st.pop();
            }

            if(st.empty()){
                startEndInd.push_back({start, i});
                start = i + 1;
            }
        }

        string ans = "";

        for(auto &i : startEndInd){
            int strt = i.first;
            int end = i.second;

            for(int k = strt+1; k < end; k++){
                ans += s[k];
            }
        }

        return ans;


    }
};