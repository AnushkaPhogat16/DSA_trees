class Solution {
public:
    string largestOddNumber(string num) {
        int end = -1;
        for(int i = num.size() - 1; i >= 0; i--){
            if(num[i] % 2 != 0){
                end = i;
                break;
            }
        }
        if(end == -1) return "";

        string ans = "";
        ans.append(num, 0, end + 1);
        return ans;
    }
};