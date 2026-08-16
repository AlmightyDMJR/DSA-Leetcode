class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
         int cnt[3] = {0, 0, 0};

        
        for (int x : stones) {
            cnt[x % 3]++;
        }

        int cnt0 = cnt[0];
        int cnt1 = cnt[1];
        int cnt2 = cnt[2];

        
        if (cnt0 % 2 == 0) {
            return cnt1 > 0 && cnt2 > 0;
        }

        
        return abs(cnt1 - cnt2) > 2;
    }
};