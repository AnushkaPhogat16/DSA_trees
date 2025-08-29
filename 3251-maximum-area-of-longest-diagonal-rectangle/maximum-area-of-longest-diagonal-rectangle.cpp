class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDsq = 0;

        for (auto &dim : dimensions) {
            int l = dim[0], w = dim[1];
            int dsq = l*l + w*w;
            int area = l*w;

            if (dsq > maxDsq) {
                maxDsq = dsq;
                maxArea = area;
            } else if (dsq == maxDsq) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
