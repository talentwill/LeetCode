// 2023-12-24

class Solution {
public:
    array<map<string, int>, 2> cache;
    int countEval(string s, int result)
    {
        if (s.empty()) {
            return 0;
        }

        if (s.length() == 1) {
            // 如果字符和期待的结果一致，则返回1
            return s[0] - '0' == result ? 1 : 0;
        }

        // 先从cache中查找是否已经计算过？
        if (cache[result].find(s) != cache[result].end()) {
            return cache[result][s];
        }

        int total_true = 0;
        int total = 0;
        for (int i = 1; i < s.length(); i += 2) {

            // 分割左右2个子表达式
            string left = s.substr(0, i);
            string right = s.substr(i + 1, s.length() - i);

            // 分别计算子表达式的四种情况
            int left_1 = countEval(left, 1);
            int left_0 = countEval(left, 0);
            int right_1 = countEval(right, 1);
            int right_0 = countEval(right, 0);

            // 计算所有可能的组合数量
            total += (left_1 + left_0) * (right_1 + right_0);

            // 根据符号计算种类
            if (s[i] == '&') {
                total_true += left_1 * right_1;
            } else if (s[i] == '|') {
                total_true += left_1 * right_1 + left_1 * right_0 + left_0 * right_1;
            } else if (s[i] == '^') {
                total_true += left_1 * right_0 + left_0 * right_1;
            }
        }
        // 把2种值分别
        cache[1][s] = total_true;
        cache[0][s] = total - total_true;
        return cache[result][s];
    }
};