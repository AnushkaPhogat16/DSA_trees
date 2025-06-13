class Solution {
public:
    const int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        // for each index :- (i - lr) * (rl - i);
        // 0 1 6 3 4 5 1
        // 0 1 2 3 4 5 6
        // for 3 -> (3 - 1)*(6-3)= 6

        // use stack for this

        vector<int> minToLeft(n);
        stack<int> st1;
        for(int i = 0; i < arr.size(); i++){
            while(!st1.empty() && arr[st1.top()] > arr[i]){
                st1.pop();
            }

            if(st1.empty()){
                minToLeft[i] = -1;
                st1.push(i);
                continue;
            }

            minToLeft[i] = st1.top();
            st1.push(i);
        }

        vector<int> minToRight(n);
        stack<int> st2;
        for(int i = n - 1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] >= arr[i]){
                st2.pop();
            }

            if(st2.empty()){
                minToRight[i] = n;
                st2.push(i);
                continue;
            }

            minToRight[i] = st2.top();
            st2.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = (ans + ((arr[i] * 1LL * (i - minToLeft[i]) % mod) * (minToRight[i] - i) % mod)) % mod;
        }

        return ans % mod;
    }
};