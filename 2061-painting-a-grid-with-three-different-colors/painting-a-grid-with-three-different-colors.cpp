class Solution {
public:
    vector<string> columnStates;
    int M = 1e9 + 7;
    vector<vector<int>> t;

    void generateColStates(string currState, char prevChar, int currL, int m){
        if(currL == m){
            columnStates.push_back(currState);
            return;
        }

        for(char ch : {'R', 'G', 'B'}){
            if(ch == prevChar){
                continue;
            }

            generateColStates(currState + ch, ch, currL + 1, m);
        }
    }

    int solve(int remainingCols, int prevStateIndex, int m){
        if(remainingCols == 0){
            return 1;
        }

        if(t[remainingCols][prevStateIndex] != -1){
            return t[remainingCols][prevStateIndex];
        }

        int ways = 0;
        string prevState = columnStates[prevStateIndex];

        for(int i = 0; i < columnStates.size(); i++){
            if(i == prevStateIndex) continue;

            string currState = columnStates[i];
            bool valid = true;

            for(int j = 0; j < m; j++){ //iterating on current nd prev states to check
                if(prevState[j] == currState[j]){
                    valid = false;
                    break;
                }

            }

            if(valid){
                ways = (ways + solve(remainingCols - 1, i, m)) % M;
            }
        }

        return t[remainingCols][prevStateIndex] = ways;
    }

    int colorTheGrid(int m, int n) {
        //generate column states as no of rows < cols

        generateColStates("", '#', 0, m);

        int totalStates = columnStates.size();
        t = vector<vector<int>>(n + 1, vector<int>(totalStates+1, -1 ));

        int result = 0;

        for(int i = 0; i < columnStates.size(); i++){
            result = (result + solve(n-1, i, m)) % M ;
        }  

        return result; 

    }
};