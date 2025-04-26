class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        
        for(int i = 0; i < answers.size(); i++){
            freq[answers[i]]++;
        }

        //answering x ie x + 1 rabbits in 1 group
        // no. of groups = no. of rabbits who answered x / x + 1
        //each group has x + 1 rabbits

        // 1 -> 2
        // 2 -> 1

        int total = 0;

        for(auto& ch : freq){
            int rabbitsInEachGroup = ch.first + 1;
            int noOfRabbitsWithAnsX = ch.second;

            int noOfGroups =ceil((double)noOfRabbitsWithAnsX / rabbitsInEachGroup);

            total += noOfGroups * rabbitsInEachGroup;
        }

        return total;


    }
};