class Solution {
public:
    int minMaxDifference(int num) {
        
        string s = to_string(num);


        char firstNon9 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '9'){
                firstNon9 = s[i];
                break;
            }
        }

        char firstNonZero = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0'){
                firstNonZero = s[i];
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
        string minNum = s;
        
        if (firstNonZero != 0) {
            for (int i = 0; i < minNum.size(); i++) {
                if (minNum[i] == firstNonZero) {
                    minNum[i] = '0';
                }
            }
        }

        int maxVal = stoi(maxNum);
        int minVal = stoi(minNum);
        return maxVal-minVal;

    }

};