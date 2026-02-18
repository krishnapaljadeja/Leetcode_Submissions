class Solution {
public:
    vector<vector<int>> dp;

    int helper(int a, int b, string &s1, string &s2) {
        if (a < 0) return b + 1;
        if (b < 0) return a + 1;

        if (dp[a][b] != -1) return dp[a][b];

        if (s1[a] == s2[b]) {
            return dp[a][b] = helper(a - 1, b - 1, s1, s2);
        }

        int insertOp  = 1 + helper(a, b - 1, s1, s2);
        int deleteOp  = 1 + helper(a - 1, b, s1, s2);
        int replaceOp = 1 + helper(a - 1, b - 1, s1, s2);

        return dp[a][b] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        dp.assign(n, vector<int>(m, -1));

        return helper(n - 1, m - 1, word1, word2);
    }
};
