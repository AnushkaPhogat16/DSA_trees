class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        for(int i = 0; i < fruits.size(); i++){

            int j = 0;

            while(j < fruits.size() && baskets[j] < fruits[i]){
                j++;
            }

            if(j == fruits.size()){
                ans++;
            }else{
                baskets[j] = 0;
            }            
        }
        return ans;
    }
};