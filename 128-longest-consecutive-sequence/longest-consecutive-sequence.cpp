class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());  // eliminate duplicates
        int longestConsecutiveSequence = 0;

        for(int num : set) {
            if(set.find(num - 1) == set.end()) {  // num is start of a sequence
                int currentNum = num;
                int currentStreak = 1;

                while(set.find(currentNum + 1) != set.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestConsecutiveSequence = max(longestConsecutiveSequence, currentStreak);
            }
        }

        return longestConsecutiveSequence;
    }
};
