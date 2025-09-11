class Solution {
public:
    string sortVowels(string s) {
        vector<char> sorted;

        for(char &c : s){
            char ch = tolower(c);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                sorted.push_back(c);
            }
        }

        sort(sorted.begin(), sorted.end());

        int j = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = tolower(s[i]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                s[i] = sorted[j];
                j++;
            }


        }

        return s;
    }
};