class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = smallest index j in word2 such that
        // word2[j...] can be matched as a subsequence
        // of word1[i...].
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                --j;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < n && j < m; ++i) {

            // Case 1: Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            }

            // Case 2: Use our one allowed mismatch
            else if (!mismatchUsed) {

                // After taking i as a mismatch,
                // word2[j+1 ...] must be obtainable exactly
                // from word1[i+1 ...].
                if (suf[i + 1] <= j + 1) {
                    ans.push_back(i);
                    ++j;
                    mismatchUsed = true;
                }
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};