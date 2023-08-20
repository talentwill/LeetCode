/**
 * @ Create Time: 2023-08-20
 */

class Solution {
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.length() != s2.length()) {
            return false;
        }
        int total = 0;
        array<int, 256> cnts {};
        for (int i = 0; i < s1.length(); i++) {
            if (++cnts[s1[i]] == 1) {
                total++;
            }
            if (--cnts[s2[i]] == 0) {
                total--;
            }
        }
        return total == 0;
    }
};