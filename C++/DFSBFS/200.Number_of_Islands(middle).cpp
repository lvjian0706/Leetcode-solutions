class Solution {
public:
    /*
    深度遍历grid：
    1. 定义坐标偏移量dx，dy，在遍历过程中，使用x+dx，y+dy来定义四个方向的相邻位置；
    2. 将visited中此时遍历到的位置赋为1；
    3. 循环遍历相邻的4个位置，当相邻点为1且visited中对应点为0时，可以从该相邻点继续进行递归遍历；
    */
    void DFS(vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y){
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            /*
            判断是否越界
            */
            if(new_x >= 0 && new_x <= grid.size()-1 && new_y >= 0 && new_y <= grid[0].size()-1){
                if(grid[new_x][new_y]=='1' && visited[new_x][new_y]==0){
                    DFS(grid, visited, new_x, new_y);
                }
            }
        }
    }

    /*
    统计网格中岛屿的数量：图的遍历问题，可以使用DFS和BFS，其中，为了避免重复遍历问题，定义visited数组记录遍历过的位置，遍历过将该位置赋为1，没有遍历过为0；
    循环遍历grid，当该点为1且visited中对应点为0时，岛屿数量加1，同时进入DFS或BFS，把相通的点都遍历到，visited对应位置修改为1；
    */
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        int num = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    num++;
                    DFS(grid, visited, i, j);
                }
            }
        }
        return num;
    }
};


class Solution {
public:
    /*
    广度遍历grid：
    1. 定义坐标偏移量dx，dy，在遍历过程中，使用x+dx，y+dy来定义四个方向的相邻位置；
    2. 定义队列存放访问到的grid为1的x，y值，将初始的x，y入队列，同时将visited[x][y]赋为1；
    3. 当队列不为空时，循环遍历队列：
    3.1 取出队头的x，y，循环遍历4个方向的相邻元素，如果该相邻点为1且visited中对应点为0时，将该相邻点位置入队列，同时将visited[new_x][new_y]赋为1；
    */
    void BFS(vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y){
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        visited[x][y] = 1;
        queue<pair<int, int>> island;
        island.push(make_pair(x, y));
        while(!island.empty()){
            int old_x = island.front().first;
            int old_y = island.front().second;
            island.pop();
            for(int i=0; i<4; i++){
                int new_x = old_x + dx[i];
                int new_y = old_y + dy[i];
                if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size()){
                    if(grid[new_x][new_y]=='1' && visited[new_x][new_y]==0){
                        island.push(make_pair(new_x, new_y));
                        visited[new_x][new_y] = 1;
                    }
                }
            }
        }
    }

    /*
    统计网格中岛屿的数量：图的遍历问题，可以使用DFS和BFS，其中，为了避免重复遍历问题，定义visited数组记录遍历过的位置，遍历过将该位置赋为1，没有遍历过为0；
    循环遍历grid，当该点为1且visited中对应点为0时，岛屿数量加1，同时进入DFS或BFS，把相通的点都遍历到，visited对应位置修改为1；
    */
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        int num = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    num++;
                    BFS(grid, visited, i, j);
                }
            }
        }
        return num;
    }
};