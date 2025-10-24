#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        effort[0][0] = 0;
        
        // Min-heap: {effort, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});
        
        vector<int> dirs = {1, 0, -1, 0, 1};
        
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int e = top[0], x = top[1], y = top[2];
            
            if (x == m - 1 && y == n - 1) return e;
            if (e > effort[x][y]) continue;
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                int newEffort = max(e, abs(heights[nx][ny] - heights[x][y]));
                if (newEffort < effort[nx][ny]) {
                    effort[nx][ny] = newEffort;
                    pq.push({newEffort, nx, ny});
                }
            }
        }
        return 0; // Should never reach here
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort Path: " 
         << sol.minimumEffortPath(heights) << endl;
    return 0;
}
