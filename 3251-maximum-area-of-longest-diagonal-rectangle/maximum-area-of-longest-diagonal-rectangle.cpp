class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDsq= 0;
        for(auto &dim : dimensions){
            int l = dim[0];
            int w = dim[1];

            int dsq = (l*l + w*w);
            if(dsq > maxDsq){
                maxArea = l*w;
            }else if(dsq == maxDsq){
                maxArea = max(maxArea, l*w);
            }

            maxDsq = max(dsq, maxDsq);


        }

        return maxArea;
    }
};