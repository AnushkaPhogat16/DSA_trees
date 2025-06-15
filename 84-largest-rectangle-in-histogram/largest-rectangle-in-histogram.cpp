class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmallerRight(n, n); // n means no smaller to the right
        vector<int> nextSmallerLeft(n, -1); // -1 means no smaller to the left

        stack<int> st;

        // Compute next smaller on right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                nextSmallerRight[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Compute next smaller on left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                nextSmallerLeft[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};
