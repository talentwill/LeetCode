class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }
        set<int> counts;
        for (auto [k, v] : freq) {
            if (counts.count(v) > 0) {
                return false;
            }
            counts.insert(v);
        }
        return true;
    }
};