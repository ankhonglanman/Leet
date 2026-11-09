class Solution {
private:
    struct coor{
        int i;
        int j;
    };

    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1}; 
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int sColor = image[sr][sc];
        int rows = image.size();
        int cols = image[0].size();

        queue<coor> to_visit; 
        to_visit.push({sr, sc});
        image[sr][sc] = color;

        while (!to_visit.empty()) {
            coor cur = to_visit.front();
            to_visit.pop();

            for (int d = 0; d < 4; d++) {
                int ihere = cur.i + di[d];
                int jhere = cur.j + dj[d];

                if (ihere < 0 || ihere >= rows || jhere < 0 || jhere >= cols) continue;

                if (image[ihere][jhere] == sColor) {
                    to_visit.push({ihere, jhere});
                    image[ihere][jhere] = INT_MAX;
                } 
            }
        }

        for (auto& row : image) {
            for (auto& pixel : row) {
                if (pixel == INT_MAX) pixel = color;
            }
        }

        return image;
    }
};