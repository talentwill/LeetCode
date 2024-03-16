// 2023-03-16
class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            return min(n, 1);
        }
        int a = 0, b = 1, c = 1;
        int d = 0;
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};