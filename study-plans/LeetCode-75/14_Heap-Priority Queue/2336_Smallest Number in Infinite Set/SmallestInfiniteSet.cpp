class SmallestInfiniteSet {
public:
    int top = 1;
    set<int> nums;
    int popSmallest() {
        if (not nums.empty()) {
            int x = *nums.begin();
            nums.erase(nums.begin());
            return x;
        }
        return top++;
    }
    void addBack(int x) {
        if (x < top) {
            nums.insert(x);
        }
    }
};