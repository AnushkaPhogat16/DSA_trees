class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int> > intervals;

        // for each char - {start index, end index}

        for(int i = 0 ; i < s.size(); i++){
            if(intervals.find(s[i]) == intervals.end()){
                intervals[s[i]] = {i , i};
            }else{
                intervals[s[i]].second = i;
            }
        }

        vector<pair<int, int>> sorted_intervals;
        for (auto& entry : intervals) {
            sorted_intervals.push_back(entry.second); // Copy the {start, end} pairs
        }

        sort(sorted_intervals.begin(), sorted_intervals.end()); // Sort by start index

        int start_ind = sorted_intervals[0].first;
        int end_ind = sorted_intervals[0].second;

        vector<pair<int, int>> mergedIntervals;

        for(auto eachInterv : sorted_intervals){
            if (eachInterv.first <= end_ind){
                end_ind = max(eachInterv.second, end_ind);
            }else{
                mergedIntervals.push_back({start_ind, end_ind});
                start_ind = eachInterv.first;
                end_ind = eachInterv.second;
            }

        }

        mergedIntervals.push_back({start_ind, end_ind});

        vector<int> ans;

        for(auto eachIntervSize : mergedIntervals){
            int size = eachIntervSize.second - eachIntervSize.first + 1;

            ans.push_back(size);
        }

        return ans;



    }
};