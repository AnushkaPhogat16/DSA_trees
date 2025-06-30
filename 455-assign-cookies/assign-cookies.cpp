class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int number= 0;
        int indS=0;
        int indG=0;

        if(s.size() == 0 ){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(indG < g.size()){
            if(s[indS] >= g[indG]){
                number++;
                indS++;
                indG++;
            }else{
                indS++;
            }

            if(indS == s.size()){
                return number;
            }
        }

        return number;
    }
};