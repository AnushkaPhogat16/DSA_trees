const int M = 1e9 + 7;

class Solution {
public:
    
    vector<long long> fact, invFact;

    int findPow(long long a, long long b){
        if(b == 0){
            return 1;
        }

        long long half = findPow(a , b /2);
        long long result = (half * half) % M;

        if(b % 2 == 1){
            result = (result * a) % M;
        }

        return result;
    }
    
    int countGoodArrays(int n, int m, int k) {
        // TOTAL no. of ways:-
        // m * comb(n-1 , k) * (m - 1)^(n - 1 - k)

        // PRECOMPUTE FACTORIALS - as need to be done repeatedly
        vector<long long> factorial(n + 1);
        factorial[0] = 1;
        factorial[1] = 1;
        for(int i = 2; i <= n; i++){
            factorial[i] = (factorial[i-1] * i) % M;
        }

        // PRECOMPUTE inverse factorial -> fermat's little theorem
        vector<long long> fermatFact(n + 1, 1);
        for(int i = 0; i <= n; i++){
            fermatFact[i] = findPow(factorial[i] , M-2);
        }

        long long result = nCr(n - 1, k, factorial, fermatFact);

        result = (result * m ) % M;

        result = (result * findPow(m - 1, n - 1 - k)) % M;

        return result;
    }

    int modPow(long long a , long long b){
        int half = modPow(a, b/2);
        int result = (half*half) % M;
        if(b % 2 == 1){
            result = (result * a) % M;
        }

        return result;
    }

    // TO APPLY nCr FORMULA
    long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermatFact){
        if(r < 0 || r > n) return 0;

        return factorial[n] * fermatFact[n-r] % M * fermatFact[r] % M; //O(1) time
    }


};