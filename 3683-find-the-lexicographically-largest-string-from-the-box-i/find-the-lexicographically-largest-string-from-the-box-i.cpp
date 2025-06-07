class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        
        string result;

        int maxLength = n - numFriends + 1;

        for(int i = 0; i < n; i++){
            int possibleLen = min(maxLength, n - i);
            result = max(result, word.substr(i, possibleLen));
        }

        return result;        
    }

};