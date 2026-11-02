class Solution {
private:
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    struct coor{
        int i; 
        int j;
    };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<coor> to_visit;
        to_visit.push({entrance[0], entrance[1]});
        int step = 0;

        maze[entrance[0]][entrance[1]] = ' ';

        while(!to_visit.empty()){
            int qSize = to_visit.size();
            step++;

            for(int idx = 0; idx < qSize; idx++){
                coor cur = to_visit.front();
                to_visit.pop();

                for(int d = 0; d < 4; d++){
                    int i = cur.i + di[d];
                    int j = cur.j + dj[d];

                    if(i >= maze.size() || i < 0 || j >= maze[0].size() || j < 0) continue;

                    if(maze[i][j] == '.'){
                        to_visit.push({i, j});
                        maze[i][j] = ' ';

                        if(i == 0 || i == maze.size() - 1 || j == 0 || j == maze[0].size() - 1) return step;
                    }
                }

            }

            
        }

        return -1;
    }
};