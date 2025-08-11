class Solution {
public:
    int M = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> result;

        //powers array 
        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0 ){
                powers.push_back(1 << i); // 2^i
            }
        }

        for(auto &q : queries){
            int start = q[0];
            int end = q[1];

            long prod = 1;
            for(int i = start; i <= end; i++){
                prod = (prod * powers[i]) % M;
            }

            result.push_back(prod);
        }

        return result;
    }
};