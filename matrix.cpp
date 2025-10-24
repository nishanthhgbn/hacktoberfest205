#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int longest = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longest = max(longest, dfs(matrix, dp, i, j));
            }
        }
        return longest;
    }

private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];
        int m = matrix.size(), n = matrix[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int maxLen = 1;
        
        for (auto& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(matrix, dp, x, y));
            }
        }
        dp[i][j] = maxLen;
        return maxLen;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    
    cout << "Longest Increasing Path Length: " 
         << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}
