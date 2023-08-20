class Solution {
public:
    string& replaceSpaces(string& S, int length)
    {
        S.resize(length + std::count(S.begin(), next(S.begin(), length), ' ') * 2);
        auto it = S.rbegin();
        for (int i = length - 1; i >= 0; i--) {
            if (S[i] == ' ') {
                *it++ = '0';
                *it++ = '2';
                *it++ = '%';
            } else {
                *it++ = S[i];
            }
        }
        return S;
    }
};