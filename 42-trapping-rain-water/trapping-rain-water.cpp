class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> lmax(h.size());
        vector<int> rmax(h.size());

        lmax[0] = h[0];
        rmax[h.size() - 1] = h[h.size() - 1];

        int lmaxVal = h[0];
        for(int i = 1; i < h.size(); i++){
            lmaxVal = max(lmaxVal , h[i]);

            lmax[i] = lmaxVal;
        }

        int rmaxVal = h[h.size() - 1];
        for(int i = h.size() - 2; i >= 0; i--){
            rmaxVal = max(rmaxVal , h[i]);

            rmax[i] = rmaxVal;
        }

        int totalWater = 0;

        for(int i = 0; i < h.size(); i++){
            // min(hmax[i], rmax[i]) - h[i];

            int height = min(rmax[i] , lmax[i]) - h[i];
            totalWater += height;
        }

        return totalWater;
    }
};

//      4 5 0 3 2 7
// lmax 4 5 5 5 5 7
// rmax 7 7 7 7 7 7
