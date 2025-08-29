class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        res.reserve(m * n);

        int i = 0, j = 0;
        bool up = true;

        while (res.size() < m * n) {
            res.push_back(mat[i][j]);

            if (up) {  // moving up-right
                if (j == n - 1) {  // hit right boundary
                    i++;
                    up = false;
                } else if (i == 0) {  // hit top boundary
                    j++;
                    up = false;
                } else {  // normal up-right move
                    i--;
                    j++;
                }
            } else {  // moving down-left
                if (i == m - 1) {  // hit bottom boundary
                    j++;
                    up = true;
                } else if (j == 0) {  // hit left boundary
                    i++;
                    up = true;
                } else {  // normal down-left move
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};
