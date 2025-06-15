class Solution {
public:
    vector<int> getNSR(const vector<int>& height) {
        int n = height.size();
        vector<int> NSR(n);
        stack<int> st;

        // Next Smaller to Right (strictly greater => pop)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && height[st.top()] > height[i]) {
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return NSR;
    }

    vector<int> getNSL(const vector<int>& height) {
        int n = height.size();
        vector<int> NSL(n);
        stack<int> st;

        // Next Smaller to Left (greater or equal => pop)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return NSL;
    }

    int findMaxArea(const vector<int>& height) {
        int n = height.size();
        auto NSR = getNSR(height);
        auto NSL = getNSL(height);

        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = NSR[i] - NSL[i] - 1;
            int area = width * height[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        // Build heights for the first row
        vector<int> height(n, 0);
        for (int j = 0; j < n; ++j)
            height[j] = (matrix[0][j] == '1');

        int maxArea = findMaxArea(height);

        // Update heights row by row and recompute
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            maxArea = max(maxArea, findMaxArea(height));
        }

        return maxArea;
    }
};
