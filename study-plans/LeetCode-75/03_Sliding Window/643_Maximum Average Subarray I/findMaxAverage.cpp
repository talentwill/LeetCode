// 2024-01-22
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double ans = 0;
        double total = 0;
        for (int i = 0; i < k; i++) {
            total += nums[i];
        }
        ans = total / k;
        for (int i = k; i < nums.size(); i++) {
            ans += nums[i] - nums[i - k];
            ans = max(ans, total / k);
        }
        return ans;
    }
};