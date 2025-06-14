class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        //push if +ve ie going right
        //if going left compare with top and pop until lesser or opposite
        //if left and stack empty add to result;

        vector<int> ans;
        
        for(int i = 0; i < ast.size(); i++){
            if(ast[i] < 0){
                while(!st.empty() && abs(ast[i]) > st.top()){
                    st.pop();
                }

                if(!st.empty() && abs(ast[i]) == st.top()){
                    st.pop();
                    continue;
                }

                if(st.empty()){
                    ans.push_back(ast[i]);
                    continue;
                }

                if(abs(ast[i]) < st.top()){
                    continue;
                }
            }else{
                st.push(ast[i]);
            }
        }

        vector<int> anss(st.size());

        for(int i = st.size() - 1; i >= 0; i--){
            anss[i] = st.top();
            st.pop();
        }

        ans.insert(ans.end(), anss.begin(), anss.end());


        return ans;

        
    }
};