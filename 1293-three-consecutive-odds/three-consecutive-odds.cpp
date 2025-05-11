class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;

        int counter = 0; 

        for(int i = 0; i < arr.size(); i++){
           if(arr[i] % 2 != 0){
            counter++;
           }else{
            counter = 0;
           }

           if(counter == 3) return true;
        }

        return false;        
    }
};