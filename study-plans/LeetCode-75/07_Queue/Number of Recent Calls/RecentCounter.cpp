// 2024-02-11
// https://leetcode.com/problems/number-of-recent-calls/?envType=study-plan-v2&envId=leetcode-75

#include <queue>
class RecentCounter {
public:
    std::queue<int> q;
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};
