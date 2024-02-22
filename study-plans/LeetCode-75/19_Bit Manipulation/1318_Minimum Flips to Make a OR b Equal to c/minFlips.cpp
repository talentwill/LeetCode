class Solution {
public:
    int minFlips(int A, int B, int C) {
        bitset<32> a(A), b(B), c(C);
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (c.test(i)) {
                if (not a.test(i) and not b.test(i)) {
                    ans++;
                }
            } else {
                if (a.test(i)) {
                    ans++;
                }
                if (b.test(i)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};