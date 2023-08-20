class Solution {
public:
    bool oneEditAway(string a, string b)
    {
        int n = a.length();
        int m = b.length();
        if (abs(n - m) > 1) {
            return false; // 长度差大于1，提前返回
        }

        if (n == m) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    cnt++;
                }
                if (cnt > 1) {
                    return false;
                }
            }
            return true;
        } else {
            if (n < m) {
                a.swap(b);
            }
            int cnt = 0;
            for (int i = 0, j = 0; i < n;) {
                if (a[i] == b[j]) {
                    i++;
                    j++;
                } else {
                    i++; // 字符串 a 跳过一个字符
                    cnt++;
                }
                if (cnt > 1) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};