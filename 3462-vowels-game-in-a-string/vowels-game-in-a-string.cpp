class Solution {
public:
    bool doesAliceWin(string s) {
        static const string vowels = "aeiouAEIOU";
        for (char ch : s) {
            if (vowels.find(ch) != string::npos) {
                return true;   
            }
        }
        return false;
    }
};
