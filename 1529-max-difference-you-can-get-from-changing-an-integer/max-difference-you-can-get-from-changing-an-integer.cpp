class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        char firstNon9;
        char firstNon1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '9'){
                firstNon9 = s[i];
                break;
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '1' && s[i] != 0){
                firstNon1 = s[i];
                break;
            }
        }

        string maxNum = s;

        if (firstNon9 != 0) {
            for (int i = 0; i < maxNum.size(); i++) {
                if (maxNum[i] == firstNon9) {
                    maxNum[i] = '9';
                }
            }
        }
        // 123456
        // 923456
        // 113456
        // 810000

        string minNum = s;
        char toReplaceMin = 0;

        // Case A: first digit > '1' → collapse all of those to '1'
        if (s[0] > '1') {
            toReplaceMin = s[0];
            for (char &c : minNum)
                if (c == toReplaceMin) c = '1';
        }
        // Case B: first digit is '1' → find first digit > '1' later, collapse those to '0'
        else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] > '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (int i = 1; i < minNum.size(); i++)
                    if (minNum[i] == toReplaceMin) minNum[i] = '0';
            }
        }



        int maxVal = stoi(maxNum);
        int minVal = stoi(minNum);
        return maxVal-minVal;
    }
};

// from left, first non 9 number -> make 9 for max
// from left first non 1 number make 1 for min