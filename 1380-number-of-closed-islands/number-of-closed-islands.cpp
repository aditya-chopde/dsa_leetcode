class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        grid[row][col] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];

            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==0){
                dfs(nrow, ncol, grid);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        // Step 1: Eliminate all 0s connected to the boundary
        // Check top and bottom rows
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 0) dfs(0, j, grid);
            if(grid[n - 1][j] == 0) dfs(n - 1, j, grid);
        }
        // Check left and right columns
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0) dfs(i, 0, grid);
            if(grid[i][m - 1] == 0) dfs(i, m - 1, grid);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};