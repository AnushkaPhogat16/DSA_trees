class Solution {
public:
    int bestStartingPoint(string &word, int n){
        int i = 0;
        int j = 1;

        while(j < n){
            int k = 0;
            while(j + k < n &&  word[i + k] == word[j + k]){
                k++;
            }

            if(j + k < n && word[j+k] > word[i+k]){
                i = j;
                j++;
            }else{
                j = j + k + 1;

            }
        }

        return i;


    }
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;

        int index = bestStartingPoint(word, n);

        int maxLength = n - numFriends + 1;
        int possibleLen = min(maxLength, (n - index));

        

        return word.substr(index, possibleLen);        
    }

};