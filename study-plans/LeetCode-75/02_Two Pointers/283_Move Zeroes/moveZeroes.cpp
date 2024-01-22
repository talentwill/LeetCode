// 2024-01-22
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int i = 0;
        int j = 0;
        int len = nums.size();
        while (i < len and j < len) {
            if (nums[i] != 0) {
                i++;
            }
            if (nums[j] == 0) {
                j++;
            }
            if (i < j && j < len) {
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
};