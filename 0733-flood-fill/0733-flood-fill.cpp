class Solution {
public:
    private:
    // Recolors all connected cells having the original color.
    void dfs(int row, int col, vector<vector<int>>& image, int oldColor, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
 
        // Base case: stop if the cell is outside the image.
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }
 
        // Base case: stop if the cell does not have the old color.
        if (image[row][col] != oldColor) {
            return;
        }
 
        // Recolor the current cell.
        image[row][col] = newColor;
 
        // Move to the upper cell.
        dfs(row - 1, col, image, oldColor, newColor);
 
        // Move to the lower cell.
        dfs(row + 1, col, image, oldColor, newColor);
 
        // Move to the left cell.
        dfs(row, col - 1, image, oldColor, newColor);
 
        // Move to the right cell.
        dfs(row, col + 1, image, oldColor, newColor);
    }
 
public:
    // Applies flood fill starting from the given cell.
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
 
        // If the new color is the same, no change is needed.
        if (oldColor == color) {
            return image;
        }
 
        // Start DFS from the given cell.
        dfs(sr, sc, image, oldColor, color);
 
        // Return the updated image.
        return image;
    
        
    }
};