class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double>& nums) {
        // Base case: only one number left
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        // Try all pairs of numbers
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                // Create a new list with remaining numbers
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // Try all operations
                for (double res : compute(nums[i], nums[j])) {
                    next.push_back(res);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    // All possible results of combining a and b
    vector<double> compute(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(b) > 1e-6) results.push_back(a / b);
        if (fabs(a) > 1e-6) results.push_back(b / a);
        return results;
    }
};
