class Solution {
public:
    int maxDifference(string s) {
       unordered_map<char, int> freq;

       for(char ch : s){
        freq[ch]++;
       } 

       int a1 = 0;
       int a2 = INT_MAX;

       for(auto &f : freq){
        if(f.second % 2 == 0){
            a2 = min(a2, f.second);

        }else{
            a1 = max(a1, f.second);
        }
       }

       
       return a1-a2;
    }
};