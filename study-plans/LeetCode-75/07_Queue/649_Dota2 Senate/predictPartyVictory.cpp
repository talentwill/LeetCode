#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    // 参考官方的题解
    // 有2个注意点，
    // 队列里面存的是下标的索引
    // while 循环里面，需要判断r和d两个队列都为空，才可以进行笔记
    //
    string predictPartyVictory(const string& senate) {
        queue<int> rad, dir;
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'D') {
                dir.push(i);
            } else {
                rad.push(i);
            }
        }
        int n = senate.length(); // n 代表一轮的个数
        while (not rad.empty() and not dir.empty()) {
            int r_id = rad.front();
            rad.pop();
            int d_id = dir.front();
            dir.pop();
            if (r_id < d_id) {
                rad.push(r_id + n); // 序号+n 或者n++，都可以
            } else {
                dir.push(d_id + n);
            }
        }
        return rad.empty() ? "Dire" : "Radiant";
    }
};
