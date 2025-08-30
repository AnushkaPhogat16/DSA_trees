class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());  // sort by start time

        int res = 0;
        int end = 0;       // current coverage
        int farthest = 0;  // farthest we can extend
        int i = 0;
        int n = clips.size();

        while (end < time) {
            // find all clips that can start before or at 'end'
            while (i < n && clips[i][0] <= end) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            if (farthest == end) return -1; // cannot extend further

            res++;       // we need one more clip
            end = farthest;
        }

        return res;
    }
};
