// 2023-09-10
lass Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // 两两交换，形成峰谷
        for (int i = 0, j = 1; j < nums.size(); i+=2, j+=2) {
            swap(nums[i], nums[j]);
        }
    }
};