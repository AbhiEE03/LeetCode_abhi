class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int initialColor, int newColor) {
        // return if the boundary is hit or a diff color wall
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != initialColor) {
            return;
        }

        // cahnge the color
        image[r][c] = newColor;

        // Move in all 4 directions 
        dfs(image, r - 1, c, initialColor, newColor); 
        dfs(image, r, c + 1, initialColor, newColor); 
        dfs(image, r + 1, c, initialColor, newColor); 
        dfs(image, r, c - 1, initialColor, newColor); 
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        
        // if initial is same as new then return
        if (initialColor == color) return image;
        
        dfs(image, sr, sc, initialColor, color);
        return image;
    }
};