class Solution {
public:
    int maxFreqSum(string s) {

        int mp[26] = {0};

        for(char ch : s){
            mp[ch - 'a']++;
        }

        int v = 0, c = 0;

        for(int i = 0; i < 26; i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                v = max(v, mp[i]);
            }else{
                c = max(c, mp[i]);
            }
        }

        int sum = v + c;

        return sum;
        
        // a e i o  u
        // 0 4 8 14 20  
    }
};