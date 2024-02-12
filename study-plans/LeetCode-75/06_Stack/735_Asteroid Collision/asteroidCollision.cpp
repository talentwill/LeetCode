#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int x: asteroids) {
            stk.push_back(x);
            while (stk.size() >= 2 and stk.back() and stk[stk.size() - 2] > 0) {
                int b1 = stk.back();
                stk.pop_back();
                int b2 = stk.back();
                stk.pop_back();
                if (abs(b1) != b2) {
                    stk.push_back(abs(b1) > b2 ? b1 : b2);
                }
            }
        }
        return stk;
    }
};
