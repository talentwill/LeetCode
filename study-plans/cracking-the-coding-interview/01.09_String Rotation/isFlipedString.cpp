class Solution {
public:
    bool isFlipedString(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false; // 长度不一样，不可能轮转
        return (s1 + s1).find(s2) != string::npos;
    }
};