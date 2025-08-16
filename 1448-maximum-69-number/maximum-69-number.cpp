class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (char &c : s) {
            if (c == '6') { 
                c = '9'; 
                break;  // only first 6 from left
            }
        }
        return stoi(s);
    }
};
