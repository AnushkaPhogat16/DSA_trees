class Solution {
public:
    string largestOddNumber(string num) {
        while (!num.empty() && ((num.back()) % 2 == 0)) {
            num.pop_back();
        }
        return num;  
    }
};
