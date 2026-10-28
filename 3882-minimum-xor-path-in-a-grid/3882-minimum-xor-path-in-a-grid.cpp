class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MAX_XOR = 1024;
        vector<vector<bitset<MAX_XOR>>> dp(m, vector<bitset<MAX_XOR>>(n));

        dp[0][0].set(grid[0][0]);

        for (int j = 1; j < n; j++) {
            for (int v = 0; v < MAX_XOR; v++) {
                if (dp[0][j - 1].test(v)) {
                    dp[0][j].set(v ^ grid[0][j]);
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int v = 0; v < MAX_XOR; v++) {
                if (dp[i - 1][0].test(v)) {
                    dp[i][0].set(v ^ grid[i][0]);
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int cellVal = grid[i][j];
                for (int v = 0; v < MAX_XOR; v++) {
                    if (dp[i - 1][j].test(v) || dp[i][j - 1].test(v)) {
                        dp[i][j].set(v ^ cellVal);
                    }
                }
            }
        }
        for (int v = 0; v < MAX_XOR; v++) {
            if (dp[m - 1][n - 1].test(v)) {
                return v;
            }
        }
        return 0;
    }
};