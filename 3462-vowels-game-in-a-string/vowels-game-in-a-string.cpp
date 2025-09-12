class Solution {
public:
    bool doesAliceWin(string s) {
        int n = 0;
        for(char &ch : s){
            if(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u'){
                n++;
            }
        }

        if( n == 0) return false;

        return true;
    }
};

//  qaweritoyu
// ifodd - true
// if even - pick any oddfirst 


    