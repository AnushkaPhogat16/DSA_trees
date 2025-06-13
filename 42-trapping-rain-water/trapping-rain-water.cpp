class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int totalWater = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottomIdx = st.top();
                st.pop();

                if (st.empty())
                    break;

                int leftIdx = st.top();
                int distance = i - leftIdx - 1;
                int boundedHeight = min(height[i], height[leftIdx]) - height[bottomIdx];

                totalWater += distance * boundedHeight;
            }
            st.push(i);
        }

        return totalWater;
    }
};
