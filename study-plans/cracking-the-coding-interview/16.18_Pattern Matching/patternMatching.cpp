// 2023-12-24

class Solution {
public:
    bool patternMatching(const string& pattern, const string& value)
    {
        int an = 0;
        int bn = 0;
        for (auto c : pattern) {
            if (c == 'a') {
                an++;
            } else {
                bn++;
            }
        }

        // 特殊处理："abab", ""
        if (value.empty()) {
            return an == 0 or bn == 0;
        }
        // "aaaa", "dogcatcatdog"
        if (an == 0 or bn == 0) {
            return singleCharMatching(pattern, value);
        }

        int nv = value.length();
        for (int i = 0; i <= nv / an; i++) {
            if ((nv - an * i) % bn == 0) {
                if (twoCharsMatching(pattern, value, i, (nv - an * i) / bn)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool singleCharMatching(const string& pattern, const string& value)
    {
        if (value.size() % pattern.size() != 0) {
            return false;
        }
        string a = value.substr(0, value.size() / pattern.size());
        for (int i = 0; i < value.length(); i++) {
            if (a[i % a.size()] != value[i]) {
                return false;
            }
        }
        return true;
    }

    bool twoCharsMatching(string_view pattern, string_view value, int lenA, int lenB)
    {
        int i = 0;
        string_view a, b;
        for (char x : pattern) {
            if (x == 'a' and lenA > 0) {
                if (a.empty()) {
                    a = value.substr(i, lenA);
                } else {
                    if (a != value.substr(i, lenA)) {
                        return false;
                    }
                }
                i += lenA;
            } else if (x == 'b' and lenB > 0) {
                if (b.empty()) {
                    b = value.substr(i, lenB);
                    if (a == b) {
                        return false;
                    }
                } else {
                    if (b != value.substr(i, lenB)) {
                        return false;
                    }
                }
                i += lenB;
            }
        }

        return true;
    }
};