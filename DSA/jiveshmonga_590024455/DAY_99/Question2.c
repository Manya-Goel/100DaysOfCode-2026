void dfs(char** grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    if (grid[r][c] != '1')
        return;

    grid[r][c] = '0';

    dfs(grid, r + 1, c, rows, cols);
    dfs(grid, r - 1, c, rows, cols);
    dfs(grid, r, c + 1, rows, cols);
    dfs(grid, r, c - 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {

            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }

    return count;
}