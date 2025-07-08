class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int orgColor, int newColor, int n, int m) {
        // Base condition
        if (x < 0 || y < 0 || x >= n || y >= m || image[x][y] != orgColor)
            return;

        image[x][y] = newColor;

        // 4 directions: up, right, down, left
        dfs(image, x - 1, y, orgColor, newColor, n, m); // up
        dfs(image, x + 1, y, orgColor, newColor, n, m); // down
        dfs(image, x, y - 1, orgColor, newColor, n, m); // left
        dfs(image, x, y + 1, orgColor, newColor, n, m); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        if (orgColor == color) return image; // Avoid infinite loop

        int n = image.size();
        int m = image[0].size();

        dfs(image, sr, sc, orgColor, color, n, m);

        return image;
    }
};
