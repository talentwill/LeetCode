// 2023-12-24
class Solution {
public:
    vector<int> masterMind(string solution, string guess)
    {
        vector<int> ans(2);
        map<char, int> a, b; // 缓存非真猜中的字符
        for (int i = 0; i < 4; i++) {
            if (solution[i] == guess[i]) {
                ans[0]++; // 真猜中答案直接计算
            } else {
                a[solution[i]]++;
                b[guess[i]]++;
            }
        }
        auto calc = [&](char c) {
            return min(a[c], b[c]); // 最小值即猜中的个数
        };
        ans[1] = calc('R') + calc('G') + calc('B') + calc('Y');
        return ans;
    }
};