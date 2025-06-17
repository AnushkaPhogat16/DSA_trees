class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int index = 0;
        int sign = 1;

        // skip leading white space
        while (index < n && s[index] == ' ') {
            index++;
        }

        // handle sign
        if (index < n && (s[index] == '+' || s[index] == '-')) {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }

        // start recursion
        return helper(s, index, sign, 0);
    }

    int helper(const string& s, int index, int sign, long result) {
        // base case -> end of string or non-digit char
        if (index >= s.size() || !isdigit(s[index])) {
            return static_cast<int>(result * sign);
        }

        int digit = s[index] - '0';

        // check for overflow before updating result
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;

        return helper(s, index + 1, sign, result);
    }
};
