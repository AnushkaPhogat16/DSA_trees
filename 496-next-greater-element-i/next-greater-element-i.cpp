class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> temp(nums1.size() , -1);

        for(int ind = 0; ind < nums1.size(); ind++){
            for(int i = 0; i < nums2.size(); i++){
                if(nums2[i] == nums1[ind]){
                    for(int j = i + 1; j < nums2.size(); j++){
                        if(nums2[j] > nums2[i]){
                            temp[ind] = nums2[j];
                            break;
                        }

                        
                    }
                }
            }
        }

        return temp;
    }
};