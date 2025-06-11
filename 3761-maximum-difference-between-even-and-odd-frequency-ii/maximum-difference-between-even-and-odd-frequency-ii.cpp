class Solution {
public:

    int getState(int count_a, int count_b){
        int parity_a = count_a % 2;
        int parity_b = count_b % 2;

        if(parity_a == 0 && parity_b == 0) return 0; // even even (00)
        if(parity_a == 0 && parity_b == 1) return 1;// even odd (01)
        if(parity_a == 1 && parity_b == 0) return 2;// odd even (10)

        return 3; // odd odd (11)
    }

    int maxDifference(string s, int k) {
        int n = s.length();
        int result = INT_MIN;

        // 1) Try all possible pairs a and b from ['0' to '4'] where a != b

        for(char a = '0'; a <= '4'; a++){
            for(char b = '0' ; b <= '4'; b++){
                if(a == b) continue;

                // for a given state, previously which min [count(a) - count(b)]

                vector<int> stateMinPrev_ab(4, INT_MAX);

                // count of a and count of b till index r
                int count_a = 0;
                int count_b = 0;

                // count of a and b till prev index l
                int prev_a = 0;
                int prev_b = 0;

                //start sliding window
                int l = -1;
                int r = 0;

                while(r < n){
                    count_a += (s[r] == a) ? 1 : 0;
                    count_b += (s[r] == b) ? 1 : 0;

                    // now try to shrink from l
                    while(r - l >= k && count_b - prev_b >= 2 && count_a - prev_a >= 1){
                        int leftState =  getState(prev_a , prev_b);

                        stateMinPrev_ab[leftState] = min(stateMinPrev_ab[leftState] , prev_a - prev_b);

                        l++;
                        prev_a += (s[l] == a) ? 1 : 0;
                        prev_b += (s[l] == b) ? 1 : 0;
                    }

                    int rightState = getState(count_a, count_b);
                    int bestLeftState = rightState ^ 2;
                    int bestMinDiffValLeft = stateMinPrev_ab[bestLeftState];

                    if(bestMinDiffValLeft != INT_MAX){
                        result = max(result, (count_a - count_b) - bestMinDiffValLeft);
                    }

                    r++;
                }
            }
        }

        return result;

    }
};