class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxPrev = values[0] + 0;
        int ans = 0;
        for(int j = 1; j < values.size(); j++){

            ans = max(ans, maxPrev + values[j] - j);
            maxPrev = max(maxPrev, values[j] + j);
            
        }

        return ans;
    }
};

// i +vi + 