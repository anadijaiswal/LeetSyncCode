class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector dp(n+1, vector<vector<int>>(m+1, vector<int>(1024, 0)));
        dp[0][0][grid[0][0]] = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                for(int k=0; k<1024; k++) {
                    if(i && dp[i-1][j][k]) {
                        dp[i][j][k ^ grid[i][j]] = 1;
                    }
                    if(j && dp[i][j-1][k]) {
                        dp[i][j][k ^ grid[i][j]] = 1;
                    }
                }
            }
        }
        for(int i=0; i<1024; i++) {
            if(dp[n-1][m-1][i]) return i;
        }
        return -1;
    }
};