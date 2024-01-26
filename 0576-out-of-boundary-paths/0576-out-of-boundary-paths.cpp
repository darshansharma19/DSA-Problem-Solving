class Solution {
public:
    const int MOD = 1000000007;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
         vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[startRow][startColumn] = 1;
    int count = 0;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int moves = 1; moves <= maxMove; moves++) {
        vector<vector<int>> temp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (const auto& dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                        count = (count + dp[i][j]) % MOD;
                    } else {
                        temp[ni][nj] = (temp[ni][nj] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        dp = temp;
    }

    return count;
        
    }
};