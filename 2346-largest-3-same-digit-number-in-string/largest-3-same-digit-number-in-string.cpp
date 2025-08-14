class Solution {
public:
    string largestGoodInteger(string num) {
        char maxDigit = 0; // store only the max digit seen
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                maxDigit = max(maxDigit, num[i]); // just compare chars
            }
        }
        return maxDigit ? string(3, maxDigit) : "";
    }
};
