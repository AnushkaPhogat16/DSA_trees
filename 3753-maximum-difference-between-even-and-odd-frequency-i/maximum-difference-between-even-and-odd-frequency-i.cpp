class Solution {
public:
    int maxDifference(string s) {
       unordered_map<char, int> freq;

       for(char ch : s){
        freq[ch]++;
       } 

       int a1MAX = 0;
       int a1MIN = INT_MAX;
       int a2MAX = 0;
       int a2MIN = INT_MAX;

       for(auto &f : freq){
        if(f.second % 2 == 0){
            a2MAX = max(a2MAX, f.second);
            a2MIN = min(a2MIN, f.second);

        }else{
            a1MAX = max(a1MAX, f.second);
            a1MIN = min(a1MIN, f.second);
        }
       }

       int diff1 = 0;
       int diff2 = 0;

       if(a1MAX != 0 && a2MIN != 0){
        diff1 = a1MAX - a2MIN;
       }

       if(a2MAX != 0 && a1MIN != 0){
        diff2 = a1MIN - a2MAX;
       }


       
       return max(diff1, diff2);
    }
};