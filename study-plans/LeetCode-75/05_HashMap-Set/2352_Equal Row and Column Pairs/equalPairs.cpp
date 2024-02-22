class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int> rows;
        for (auto& row : grid) {
            rows[row]++;
        }
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> col;
            for (int j = 0; j < n; j++) {
                col.emplace_back(grid[j][i]);
            }
            auto it = rows.find(col);
            if (it != rows.end()) {
                ans += it->second;
            }
        }
        return ans;
    }
};