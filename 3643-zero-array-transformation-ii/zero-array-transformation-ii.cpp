class Solution {
public:
    int n;
    int q;

    bool checkWithDiffArr(vector<int>& nums, vector<vector<int>>& queries, int k){
        vector<int> diff(n, 0);

        for(int i = 0; i <= k; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int X = queries[i][2];

            diff[start] += X;
            if(end + 1 < n){
                diff[end + 1] -= X;
            }
        }

        int cumSum = 0;
        for(int i = 0; i < n; i++){
            cumSum += diff[i];
            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0){
                return false;
            }
        }

        return true;
    }


    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        q = queries.size();
        n = nums.size();

        bool alreadyZero = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                alreadyZero = false;
                break;
            }
        }

        if(alreadyZero == true) return 0;

        int l = 0; 
        int r = q-1;

        int k = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(checkWithDiffArr(nums, queries, mid) == true){
                k = mid+1;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return k;
    }
};
