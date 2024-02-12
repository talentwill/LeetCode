class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s1 { nums1.begin(), nums1.end() };
        set<int> s2 { nums2.begin(), nums2.end() };
        vector<vector<int>> ans(2);
        std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
            std::back_inserter(ans[0]));
        std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
            std::back_inserter(ans[1]));
        return ans;
    }
};