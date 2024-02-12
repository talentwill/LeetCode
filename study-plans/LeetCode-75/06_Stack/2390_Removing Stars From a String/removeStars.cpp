#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string stk;
        for (char c: s) {
            if (c == '*') {
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk;
    }
};
