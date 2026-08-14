class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int freq[26]={};
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            int c = s[right] - 'a';
            freq[c]++;

            // Character occurs more than twice
            while (freq[c] > 2) {
                int leftChar = s[left] - 'a';
                freq[leftChar]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};