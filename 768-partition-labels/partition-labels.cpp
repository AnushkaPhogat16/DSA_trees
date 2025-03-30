class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0); // Stores the last occurrence of each character

        // Step 1: Find the last index of each character in the string
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;  // Store last occurrence index
        }

        // Step 2: Traverse again to form partitions
        vector<int> ans;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);  // Expand the partition to include all occurrences

            if (i == end) { // If we reach the end of a partition
                ans.push_back(end - start + 1); 
                start = i + 1; // Start a new partition
            }
        }

        return ans;
    }
};
