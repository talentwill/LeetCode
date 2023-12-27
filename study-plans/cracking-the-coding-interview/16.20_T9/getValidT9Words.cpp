// 2023-12-26

class Solution {
public:
    char getDigitChar(char x) {
        if (x <= 'c') return '2';
        if (x <= 'f') return '3';
        if (x <= 'i') return '4';
        if (x <= 'l') return '5';
        if (x <= 'o') return '6';
        if (x <= 's') return '7';
        if (x <= 'v') return '8';
        if (x <= 'z') return '9';
        return '1';
    }

    bool equal(const string& word, const string& num)
    {
        // 单词长度不一致
        if (word.length() != num.length()) {
            return false;
        }
        for (int i = 0; i < word.length(); i++) {
            // 将单词转换成digit，比较每一个num的数字是否一致
            if (getDigitChar(word[i]) != num[i]) {
                return false;
            }
        }
        return true;
    }

    vector<string> getValidT9Words(string num, vector<string>& words)
    {
        vector<string> ans;
        for (const auto& word : words) {
            if (equal(word, num)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};