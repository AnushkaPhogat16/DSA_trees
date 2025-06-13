class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> nextGrt;

        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }

            nextGrt[nums2[i]] = (!st.empty()) ? st.top() : -1;
            
            st.push(nums2[i]);
        }

        vector<int> temp(nums1.size());

        for(int i = 0; i < nums1.size(); i++){
            if(nextGrt.find(nums1[i]) != nextGrt.end()){
                temp[i] = nextGrt[nums1[i]];
            }
        }

        return temp;


        
    }
};


