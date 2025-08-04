class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;

        int ans = 0;

        int l = 0; 
        int r = 0;        

        while(r< fruits.size()){
            f[fruits[r]]++;
            while(f.size() > 2){
                if (--f[fruits[l]] == 0) f.erase(fruits[l]);                    
                l++;  
            }
            
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;

    }
};