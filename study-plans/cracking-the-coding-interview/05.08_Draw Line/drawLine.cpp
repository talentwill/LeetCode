
class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y)
    {
        vector<int> ans(length);
        int row = y * (w / 32); // 像素在第几行

        // 起始像素的坐标
        int index1 = row + x1 / 32;
        int offset1 = x1 % 32;

        // 结束像素的坐标
        int index2 = row + x2 / 32;
        int offset2 = x2 % 32;

        // 填充函数，方便进行实现替换
        auto fill = [&](int index, int first, int last) {
            for (int i = 31 - last; i <= 31 - first; i++) {
                ans[index] |= 1 << i;
            }
        };

        if (index1 == index2) {
            fill(index1, offset1, offset2);
        } else {
            fill(index1, offset1, 31);
            fill(index2, 0, offset2);
            for (int i = index1 + 1; i < index2; i++) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};