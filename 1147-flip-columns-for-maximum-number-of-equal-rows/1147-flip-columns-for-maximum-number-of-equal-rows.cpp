class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // i-th row
            int c = 1;
            for (int j = i + 1; j < n; j++)
            {
                // j-th row
                bool f1 = 1, f2 = 0;
                for (int k = 0; k < m; k++)
                {
                    f1 &= (matrix[i][k] ^ matrix[j][k]);
                    f2 |= (matrix[i][k] ^ matrix[j][k]);
                }
                if (f1 || !f2)
                    c++;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};