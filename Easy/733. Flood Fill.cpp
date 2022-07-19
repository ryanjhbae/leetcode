class Solution {
public:
    bool inBounds(vector<vector<int>> &image, int x, int y) {
        if (x >= image.size() || x < 0) return false;
        else if (y >= image[x].size() || y < 0) return false;
        else return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        std::stack<std::pair<int, int>> pixelsToFill;
        int original_color = image[sr][sc];
        // edge case! if the color you're trying to fill is the original color, then
        //   all pixels 4-directionally connected to image[sr][sc] should already be filled
        //   with color
        if (color == original_color) return image;
        pixelsToFill.emplace(sr, sc);
        while (!pixelsToFill.empty()) {
            std::pair<int,int> pixel = pixelsToFill.top();
            pixelsToFill.pop();
            int x = pixel.first;
            int y = pixel.second;
            image[x][y] = color;
            
            // checking that the pixel we want to fill is the original color is
            //   crucial for not only ensuring that it is 4-way connected to image[sr][sc]
            //   but also for preventing infinite loops
            // top
            if (inBounds(image, x, y + 1) && image[x][y + 1] == original_color) {
                pixelsToFill.emplace(x, y + 1);
            }
            // bottom
            if (inBounds(image, x, y - 1) && image[x][y - 1] == original_color) {
                pixelsToFill.emplace(x, y - 1);
            }
            // left
            if (inBounds(image, x - 1, y) && image[x - 1][y] == original_color) {
                pixelsToFill.emplace(x - 1, y);
            }
            // right
            if (inBounds(image, x + 1, y) && image[x + 1][y] == original_color) {
                pixelsToFill.emplace(x + 1, y);
            }
        }
        return image;
    }
};