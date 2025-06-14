class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        
        vector<int> result(temps.size() , 0);
        stack<pair<int, int>> st; // {temperature, ans};

        for(int i = temps.size() - 1; i >= 0; i--){

            if(st.empty()){
                st.push({temps[i] , 0});
                result[i] = 0;
                continue;
            }

            int days = 1;            

            while(!st.empty() && st.top().first <= temps[i]){
                days += st.top().second;
                st.pop();
            }

            if(st.empty()){
                st.push({temps[i] , 0});
                result[i] = 0;
            }else{
                st.push({temps[i] , days});
                result[i] = days;
            }


        }

        return result;
        
    }
};