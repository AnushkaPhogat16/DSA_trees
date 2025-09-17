class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26,false);

        for(char c : brokenLetters){
            broken[c-'a'] = true;
        }

        int ans = 0;

        bool np = true;

        for(int i = 0; i < text.size(); i++){

            if(text[i] == ' '){
                if(np == true) ans++;
                
                np=true;
                continue;
            }

            int val =tolower(text[i]) - 'a';

            if(broken[val]){
                np=false;
            }

            if(i == text.size() -1 && np == true){
                ans++;
            }
           
        }


        return ans;
    }
};