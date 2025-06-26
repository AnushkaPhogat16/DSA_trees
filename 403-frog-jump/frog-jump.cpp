class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];

    bool solve(vector<int>& stones, int currStoneInd, int prevJump){
        if(currStoneInd == n- 1){
            return true;
        }

        if(t[currStoneInd][prevJump] != -1){
            return t[currStoneInd][prevJump] ;
        }

        bool result = false;

        for(int nextJmp = prevJump - 1; nextJmp <= prevJump + 1; nextJmp++){
            if(nextJmp > 0 ){
                int nextStone = stones[currStoneInd] + nextJmp;

                if(mp.find(nextStone) != mp.end()){
                    result = result || solve(stones, mp[nextStone], nextJmp);
                }
            }
        }

        return t[currStoneInd][prevJump] = result;

    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }

        memset(t, -1, sizeof(t)); 

        return solve(stones, mp[0], 0);        
    }
};