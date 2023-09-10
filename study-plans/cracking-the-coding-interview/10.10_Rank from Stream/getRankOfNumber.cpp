// 2023-09-10
class StreamRank
{
public:
    map<int, int> mp;

    void track(int x)
    {
        mp[x] += 1;
    }

    int getRankOfNumber(int x)
    {
        int ret = 0;
        for (auto [k, v] : mp)
        {
            if (k > x)
            {
                break;
            }
            ret += v;
        }
        return ret;
    }
};
