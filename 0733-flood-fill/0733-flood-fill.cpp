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

        vector<vector<bool>> visited;
        visited.reserve(rows);

        for (int i = 0; i < rows; i++) {
            vector<bool> vec;
            vec.reserve(cols);
            for (int j = 0; j < cols; j++) {
                vec.push_back(false);
            }
            visited.push_back(vec);
        }

        while (!to_visit.empty()) {
            coor cur = to_visit.front();
            to_visit.pop();

            for (int d = 0; d < 4; d++) {
                int ihere = cur.i + di[d];
                int jhere = cur.j + dj[d];

                if (ihere < 0 || ihere >= rows || jhere < 0 || jhere >= cols) continue;

                if (!visited[ihere][jhere] && image[ihere][jhere] == sColor) {
                    visited[ihere][jhere] = true;
                    to_visit.push({ihere, jhere});
                    image[ihere][jhere] = color;
                } 
            }
        }

        return image;
    }
};