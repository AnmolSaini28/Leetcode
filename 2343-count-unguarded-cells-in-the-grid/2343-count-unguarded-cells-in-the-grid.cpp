class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        int gsize = guards.size(), wsize = walls.size();

     //if every matrix cell contian a guard or a wall 
    // then there are no unoccupied cells that are not guarded.
        if (n * m - gsize - wsize == 0)
            return 0;

    // build the matrix initialize its cell to 0
    //0 index to unguarded cell
        vector<vector<int>> matrix(m, vector<int>(n, 0));
    
    // mark every wall position with -1 
        for ( auto& wall : walls) {
            int row = wall[0], col = wall[1];
            matrix[row][col] = -1;
        }
    
    // mark every guard position with 1 
        for ( auto& guard : guards) {
            int row = guard[0], col = guard[1];
            matrix[row][col] = 1;
        }

    //for every guard mark the cells he can guard:
    //chaeck the four cardinal directions   
        for (const auto& guard : guards) {
            int row = guard[0], col = guard[1];
            for (int j = row + 1; j < m; j++) {
                if (matrix[j][col] == 1 || matrix[j][col] == -1)
                    break;
                matrix[j][col] = 2;
            }
            for (int j = col + 1; j < n; j++) {
                if (matrix[row][j] == 1 || matrix[row][j] == -1)
                    break;
                matrix[row][j] = 2;
            }
            for (int j = row - 1; j >= 0; j--) {
                if (matrix[j][col] == 1 || matrix[j][col] == -1)
                    break;
                matrix[j][col] = 2;
            }
            for (int j = col - 1; j >= 0; j--) {
                if (matrix[row][j] == 1 || matrix[row][j] == -1)
                    break;
                matrix[row][j] = 2;
            }
        }
    // count the number of unoccupied cells and return it
        int count = 0;
        for (const auto& row : matrix) {
            for (const auto& cell : row) {
                if (cell == 0)
                    count++;
            }
        }
        return count;
    }
};