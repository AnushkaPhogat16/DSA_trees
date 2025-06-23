class Solution {
public:
    vector<string> result;

    void helper(string& num, int idx, long eval, long prev, string expr, int target){

        if(idx == num.size()){
            if(eval == target) result.push_back(expr);

            return;
        }

        for(int i = idx; i < num.size(); i++){
            if(i != idx && num[idx] == '0') break ;//skip leading zeroes
            string currStr = num.substr(idx, i - idx + 1);
            long curr = stol(currStr);

            if(idx == 0){
                helper(num, i + 1, curr, curr, currStr, target);
            }else{
                helper(num, i + 1, eval + curr, curr, expr + "+" + currStr, target);
                helper(num, i + 1, eval - curr, -curr, expr + "-" + currStr, target);
                helper(num, i + 1, eval - prev + prev * curr, prev * curr, expr + "*" + currStr, target);
            }
        }

    }

    vector<string> addOperators(string num, int target) {
        helper(num, 0, 0, 0, "", target);
        return result;
    }
};