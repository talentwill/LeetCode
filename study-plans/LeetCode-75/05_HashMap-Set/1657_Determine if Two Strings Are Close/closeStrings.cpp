class Solution {
public:
    map<int, int> frequency(const string& w) {
        map<int, int> freq;
        for (auto c: w) {
            freq[c]++;
        }
        map<int, int> result;
        for (auto [k, v]: freq) {
            result[v]++;
        }
        return result;
    }

    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        set<char> s1 { word1.begin(), word1.end() };
        set<char> s2 { word2.begin(), word2.end() };
        if (s1 != s2) {
            return false;
        }
        return frequency(word1) == frequency(word2);
    }
};
