class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int old, int neww) {
        int m = image.size();
        int n = image[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n)
            return;
        if (image[r][c] != old)
            return;
        image[r][c] = neww;

        dfs(image, r - 1, c, old, neww);
        dfs(image, r + 1, c, old, neww);
        dfs(image, r, c - 1, old, neww); 
        dfs(image, r, c + 1, old, neww); 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {

        int old = image[sr][sc];
        if (old == color)
            return image;
        dfs(image, sr, sc, old, color);

        return image;
    }
};