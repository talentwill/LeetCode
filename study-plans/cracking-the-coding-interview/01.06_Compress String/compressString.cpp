class Solution {
public:
    string compressString(string S)
    {
        if (S.empty())
            return "";

        string ans(1, S[0]);
        int n = 0;
        for (auto c : S) {
            if (ans.back() == c) {
                n++;
            } else {
                ans += to_string(n);
                n = 1;
                ans.push_back(c);
            }
        }

        ans += to_string(n);
        if (ans.length() >= S.length()) {
            return S;
        }
        return ans;
    }
};