class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        const int MAX = 1001;
        vector<int> spf(MAX);  // spf[i] = smallest prime factor of i
        for (int i = 0; i < MAX; i++) spf[i] = i;

        // Precompute SPF using sieve
        for (int i = 2; i * i < MAX; ++i) {
            if (spf[i] == i) {  // i is prime
                for (int j = i * i; j < MAX; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        unordered_set<int> primes;

        // Use SPF to factor numbers in nums
        for (int num : nums) {
            while (num > 1) {
                int p = spf[num];
                primes.insert(p);
                while (num % p == 0) num /= p;
            }
        }

        return primes.size();
    }
};
