class Solution {
public:

    bool nonzero(int x){
        while(x > 0){
            int rem = x%10;
            x = x/10;

            if(rem == 0) return false;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        int num1 = 0;
        int num2 = 0;
        
        for(int i = 1; i < n; i++){
            num1 = i;
            num2 = n - i;

            if(nonzero(num1) && nonzero(num2)){
                return {num1, num2};
            }
        }

        return {num1, num2};
    }
};