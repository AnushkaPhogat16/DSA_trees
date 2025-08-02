class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq1, freq2, totalf;

        for(int v : basket1){
            freq1[v]++;
            totalf[v]++;
        }
        for(int v : basket2){
            freq2[v]++;
            totalf[v]++;
        }

        for(auto& f : totalf){
            if(f.second % 2 != 0) return -1;
        }

        vector<int> excess1, excess2;
        int global_min = INT_MAX;
        
        for(auto& [val, _ ] : totalf){
            int need = totalf[val] / 2;
            int extra1 = freq1[val] > need ? freq1[val] - need : 0;
            int extra2 = freq2[val] > need ? freq2[val] - need : 0;

            for(int i = 0; i < extra1; i++) excess1.push_back(val);
            for(int i = 0; i < extra2; i++) excess2.push_back(val);

            global_min = min(global_min , val);
        }

        sort(excess1.begin(), excess1.end());
        sort(excess2.begin(), excess2.end(),  greater<int>());
        long long cost = 0;
        int n = excess1.size();

        for(int i = 0; i < n; i++){
            int a = excess1[i];
            int b = excess2[i];

            cost += min(1LL * min(a,b) , 2LL * global_min);
        }

        return cost;



    }
};