class TripleInOne {
public:
    static constexpr int N = 3;
    vector<int> stacks;
    array<int, N> tops, btms;
    int size;

    TripleInOne(int stackSize)
        : size(stackSize)
    {
        stacks.resize(size * N); // 初始化3个栈的大小
        for (int i = 0; i < N; i++) {
            btms[i] = i * size; // 栈底下标
            tops[i] = btms[i] - 1; // 栈顶下标
        }
    }

    void push(int i, int value)
    {
        if (tops[i] - btms[i] + 1 < size) {
            stacks[++tops[i]] = value;
        }
    }

    int pop(int i)
    {
        if (isEmpty(i))
            return -1;
        return stacks[tops[i]--];
    }

    int peek(int i)
    {
        if (isEmpty(i))
            return -1;
        return stacks[tops[i]];
    }

    bool isEmpty(int i)
    {
        return tops[i] < btms[i];
    }
};